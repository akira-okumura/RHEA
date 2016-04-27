void GaussFit() {
  TH1D* hist = new TH1D("h", ";#it{x};Entries", 50, -5, 5);
  hist->FillRandom("gaus", 1000);
  hist->Fit("gaus");
}
