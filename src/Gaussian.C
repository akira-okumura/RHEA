void Gaussian() {
  const Int_t kN = 4;
  const Double_t kSigma[kN] = {1., 3., .5, 2.};
  const Double_t kMean[kN] = {0., 0., 1., -2.};
  TF1* f[kN];
  TLegend* leg = new TLegend(0.15, 0.6, 0.4, 0.85);

  for (Int_t i = 0; i < kN; ++i) {
    f[i] =
        new TF1(Form("Gauss%d", i),
                "1/(2*pi*[0]**2)**0.5*exp(-(x-[1])**2/(2*[0]**2))", -10., 10.);
    f[i]->SetParameter(0, kSigma[i]);
    f[i]->SetParameter(1, kMean[i]);
    f[i]->SetLineColor(i + 1);
    f[i]->SetLineStyle(i + 1);
    f[i]->SetNpx(1000);
    f[i]->Draw(i == 0 ? "" : "same");

    if (i == 0) {
      f[i]->GetXaxis()->SetTitle("#it{x}");
      f[i]->GetYaxis()->SetTitle("#it{f}(#it{x})");
      f[i]->SetTitle("");
      f[i]->GetYaxis()->SetRangeUser(0, 1);
    }

    leg->AddEntry(
        f[i], Form("#it{#mu} = %4.1f, #it{#sigma} = %.1f", kMean[i], kSigma[i]),
        "l");
  }

  leg->Draw();
}
