void first_script2_wo_new(int nbins, int nevents) {
  TH1D hist("myhist", "Gaussian Histogram (#sigma = 1)", nbins, -5, 5);
  hist.FillRandom("gaus", nevents);
  hist.Draw();
}
