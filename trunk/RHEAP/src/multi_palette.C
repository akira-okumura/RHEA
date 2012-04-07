void multi_palette()
{
  gStyle->SetOptStat(0);

  TCanvas* can = new TCanvas("can", "can", 400, 600);
  can->Divide(2, 3, 1e-10, 1e-10);
  
  TH2D* hist  = new TH2D("hist", "", 50, -5, 5, 50, -5, 5);
  hist->SetContour(100);

  for(int i = 0; i < 100000; i++){
    double x = gRandom->Gaus();
    double y = gRandom->Gaus();
    hist->Fill(x, y);
  } // i

  gROOT->ProcessLine(".L color_def.C");

  TExec* exe[6];

  exe[0] = new TExec("ex0", "gStyle->SetPalette(0);");
  exe[1] = new TExec("ex1", "gStyle->SetPalette(1);");
  exe[2] = new TExec("ex2", "GrayPalette();");
  exe[3] = new TExec("ex3", "GrayInvPalette();");
  exe[4] = new TExec("ex4", "BPalette();");
  exe[5] = new TExec("ex5", "RBPalette();");

  for(int i = 0; i < 6; i++){
    gPad = can->cd(i + 1);
    hist->Draw("axis z");
    exe[i]->Draw();
    hist->Draw("same colz");
    gPad->Update();
  } // i
}
