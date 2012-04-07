void first_script2(int nbins, int nevents)
{
  TH1D* hist = new TH1D("myhist", "Gaussian Histogram", nbins, -5, 5);
  hist->FillRandom("gaus", nevents);
  hist->Draw();
}
