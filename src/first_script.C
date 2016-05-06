void first_script() {
  TH1D* hist = new TH1D("myhist", "Gaussian Histogram (#sigma = 1)", 50, -5, 5);
  hist->FillRandom("gaus", 10000);
  hist->Draw();
}
