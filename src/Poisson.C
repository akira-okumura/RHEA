void Poisson() {
  const Int_t kN = 5;
  const Double_t kLambda[kN] = {1, 3, 10, 20, 30};

  TCanvas* can = new TCanvas;
  can->DrawFrame(-5, 0, 50, 0.4, ";#it{k};Probability");

  TGraph* graphP[kN];
  TGraph* graphG[kN];

  TLegend* leg = new TLegend(0.3, 0.65, 0.85, 0.85);

  for (Int_t i = 0; i < kN; ++i) {
    graphP[i] = new TGraph;
    for (Int_t j = 0; j <= 50; ++j) {
      graphP[i]->SetPoint(j, j, TMath::PoissonI(j, kLambda[i]));
    }
    graphP[i]->Draw("pl same");
    graphP[i]->SetMarkerColor(i + 1);
    graphP[i]->SetMarkerStyle(20 + i);
    graphP[i]->SetLineColor(i + 1);
  }

  for (Int_t i = 0; i < kN; ++i) {
    graphG[i] = new TGraph;
    for (Int_t j = -5; j <= 40; ++j) {
      Double_t p = (TMath::Erf((j + 0.5 - kLambda[i])/TMath::Sqrt(2*kLambda[i])) + 1)/2.
        - (TMath::Erf((j - 0.5 - kLambda[i])/TMath::Sqrt(2*kLambda[i])) + 1)/2.;
      graphG[i]->SetPoint(j + 5, j, p);
    }
    graphG[i]->Draw("l same");
    graphG[i]->SetLineStyle(2);
    graphG[i]->SetLineColor(i + 1);
  }

  for (Int_t i = 0; i < kN; ++i) {
    leg->AddEntry(graphP[i], Form("Poisson (#it{#lambda} = %2.0f)", kLambda[i]), "lp");
    leg->AddEntry(graphG[i], Form("Gaussian (#it{#mu} = %2.0f, #it{s} = #sqrt{%2.0f})", kLambda[i], kLambda[i]), "l");
  }

  leg->SetNColumns(2);
  leg->Draw();
}
