void Chi2() {
  TH1D* h = new TH1D("h", "", 100, 0, 30);

  for (int j = 0; j < 100000; ++j) {
    TGraphErrors graph;
    for (int i = 0; i < 10; ++i) {
      double x = i;
      double y = i + gRandom->Gaus(); // Add fluctuation with a sigma of 1
      double ex = 0;
      double ey = 1.;
      graph.SetPoint(i, x, y);
      graph.SetPointError(i, ex, ey);
    }
    graph.Fit("pol1", "q0");
    double chi2 = graph.GetFunction("pol1")->GetChisquare();
    h->Fill(chi2);
  }

  TF1* pdf = new TF1("pdf", "ROOT::Math::chisquared_pdf(x, [0], 0)", 0, 30);
  pdf->SetTitle("#chi^{2} Distribution for #nu = 8;#chi^{2};Probability");
  pdf->SetParameter(0, 8);
  pdf->SetNpx(500);
  pdf->Draw();

  h->Scale(1./ h->GetEntries() / h->GetXaxis()->GetBinWidth(1));
  h->Draw("same");
}
