void StandardError() {
  const Int_t kSampleSize = 10000;
  const Int_t kRepeat = 10000;
  const Double_t kMean = 0.;
  const Double_t kSigma = 1.;

  TH1D* hMeanError = new TH1D("hMeanError", ";<#it{x}>", 100, -0.05, 0.05);
  TH1D* hStdDevError =
      new TH1D("hStdDevError", ";#it{#sigma}_{#it{x}}", 100, -0.05, 0.05);

  for (Int_t i = 0; i < kRepeat; ++i) {
    TH1D h("", "", 100, -5, 5);
    for (Int_t j = 0; j < kSampleSize; ++j) {
      Double_t x = gRandom->Gaus(kMean, kSigma);
      h.Fill(x);
    }
    hMeanError->Fill(h.GetMean() - kMean);
    hStdDevError->Fill(h.GetStdDev() - kSigma);
  }

  TCanvas* can = new TCanvas("can", "can", 1200, 600);
  can->Divide(2, 1, 1e-10, 1e-10);
  can->cd(1);
  hMeanError->Draw();
  can->cd(2);
  hStdDevError->Draw();
}
