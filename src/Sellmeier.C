Bool_t reject;

Double_t SellmeierFormula(Double_t *x, Double_t *par) {
  // n^2(lambda) = 1 + B1*lamda^2/(lamda^2 - C1) + B2*lamda^2/(lamda^2 - C2)
  //                 + B3*lamda^2/(lamda^2 - C3)
  // where lambda is measured in (um)

  if (reject && ((420. < x[0] && x[0] < 640.) || x[0] < 305.)) {
    TF1::RejectPoint();
    return 0;
  }

  // Convert (nm) to (um)
  Double_t lambda2 = TMath::Power(x[0] / 1000., 2.);
  return TMath::Sqrt(1 + par[0] * lambda2 / (lambda2 - par[3]) +
                     par[1] * lambda2 / (lambda2 - par[4]) +
                     par[2] * lambda2 / (lambda2 - par[5]));
}

void Sellmeier() {
  reject = kTRUE;
  TF1 *sellmeier = new TF1("sellmeier", SellmeierFormula, 300, 800, 6);
  sellmeier->SetParameter(0, 1.12);
  sellmeier->SetParLimits(0, 0.8, 1.2);
  sellmeier->SetParameter(1, 0.31);
  sellmeier->SetParLimits(1, 0.1, 0.5);
  sellmeier->SetParameter(2, 0.88);
  sellmeier->SetParLimits(2, 0.6, 1.1);
  sellmeier->SetParameter(3, 0.0064);
  sellmeier->SetParLimits(3, 0.004, 0.009);
  sellmeier->SetParameter(4, 0.022);
  sellmeier->SetParLimits(4, 0.01, 0.04);
  sellmeier->SetParameter(5, 107.);
  sellmeier->SetParLimits(5, 50, 150);
  sellmeier->SetParName(0, "B1");
  sellmeier->SetParName(1, "B2");
  sellmeier->SetParName(2, "B3");
  sellmeier->SetParName(3, "C1");
  sellmeier->SetParName(4, "C2");
  sellmeier->SetParName(5, "C3");

  TGraph *graph = new TGraph("UVC-200B.csv", "%lg,%lg,%*lg");
  graph->SetTitle(";Wavelength (nm);Refractive Index;");
  graph->Draw("ap");
  graph->Fit("sellmeier", "w m e 0", "", 300, 700);

  reject = kFALSE;
  TF1* sellmeier2 = new TF1("sellmeier2", SellmeierFormula, 300, 700, 6);
  sellmeier2->SetParameters(sellmeier->GetParameters());
  sellmeier2->SetLineWidth(1);
  sellmeier2->SetLineColor(2);
  sellmeier2->Draw("l same");
}
