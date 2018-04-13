void residual() {
  TGraphErrors* gra = new TGraphErrors();
  gra->SetTitle(";Time (s);Voltage (V)");
  for (int i = 0; i < 20; ++i) {
    double x = i + 0.5;
    double y = 5 * sin(x);
    double ey = gRandom->Gaus();
    gra->SetPoint(i, x, y + ey);
    gra->SetPointError(i, 0, 1);
  }

  TCanvas* can = new TCanvas("can", "can");
  can->cd(1);
  can->SetBottomMargin(0.3);

  TF1* f1 = new TF1("f1", "[0] + [1]*sin(x)", 0, 20);
  f1->SetParameter(0, 0.);
  f1->SetParameter(1, 0.9);
  gra->Fit("f1");
  gra->GetXaxis()->SetLabelSize(0);
  gra->GetXaxis()->SetTitleSize(0);
  gra->GetXaxis()->SetLimits(0, 20);
  gra->GetHistogram()->SetMaximum(9.);
  gra->GetHistogram()->SetMinimum(-9.);
  gra->Draw("ape");

  TPad* pad = new TPad("pad", "pad", 0., 0., 1., 1.);
  pad->SetTopMargin(0.7);
  pad->SetFillColor(0);
  pad->SetFillStyle(0);
  pad->Draw();

  TGraphErrors* res = new TGraphErrors();
  res->SetTitle(";Time (s);#chi");

  for (int i = 0; i < 20; ++i) {
    double x = gra->GetX()[i];
    double y = gra->GetY()[i];
    double ey = gra->GetErrorY(i);
    res->SetPoint(i, x, (y - f1->Eval(x)) / ey);
    res->SetPointError(i, 0, 1);
  }

  pad->cd(0);
  res->GetXaxis()->SetLimits(0, 20);
  res->GetHistogram()->SetMaximum(3.5);
  res->GetHistogram()->SetMinimum(-3.5);
  res->GetYaxis()->CenterTitle();
  res->GetYaxis()->SetNdivisions(110);
  res->Draw("ape");
}
