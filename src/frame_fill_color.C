void frame_fill_color() {
  gStyle->SetOptStat(0);

  TCanvas* can = new TCanvas("can", "can", 400, 400);

  TH2D* hist = new TH2D("hist", "", 50, -5, 5, 50, -5, 5);
  hist->SetContour(100);
  hist->GetXaxis()->SetAxisColor(0);
  hist->GetYaxis()->SetAxisColor(0);

  for (int i = 0; i < 100000; ++i) {
    double x = gRandom->Gaus();
    double y = gRandom->Gaus();
    hist->Fill(x, y);
  } // i

  gROOT->ProcessLine(".L color_def.C");
  BPalette();
  hist->Draw("colz");
  gPad->Update();
  TPaletteAxis* palette =
      (TPaletteAxis*)hist->GetListOfFunctions()->FindObject("palette");
  Int_t col = palette->GetValueColor(hist->GetMinimum());
  hist->Draw("colz");
  gPad->SetFrameFillColor(col);
  gPad->Update();
}
