void lat_resolution(const char* directory) {

  TChain* chain = new TChain("photons");
  for(int i = 9; i < 50; i++) {
    chain->Add(Form("%s/lat_photon_weekly_w%03d_p302_v001_extracted.root", directory, i));
  }

  const double kLongitude = 184.33;
  const double kLatitude = -5.47;

  TCut cut1("cut1", "ENERGY > 200");
  TCut cut2("cut2", "ENERGY > 1000");

  TCanvas* can = new TCanvas("can", "can", 800, 800);
  can->Divide(2, 2);

  TH2F* hCrab[3];
  TH1D* prox[3];

  for(int i = 0; i < 3; i++) {
    can->cd(i + 1);
    hCrab[i] = new TH2F(Form("hCrab%d", i),
                        ";Galactic Longitude (deg);Galactic Latitude (deg)",
                        100, kLongitude - 3, kLongitude + 3,
                        100, kLatitude - 3, kLatitude + 3);
    if (i == 0) {
      chain->Draw("B:L>>hCrab0", !cut1, "colz");
    } else if(i == 1) {
      chain->Draw("B:L>>hCrab1", cut1&&(!cut2), "colz");
    } else {
      chain->Draw("B:L>>hCrab2", cut2, "colz");
    }
    
    prox[i] = hCrab[i]->ProjectionX(Form("pro%d", i));
    prox[i]->SetMinimum(0);
    prox[i]->SetMarkerColor(i + 1);
    prox[i]->SetLineColor(i + 1);

    can->cd(4);
    prox[i]->Draw(i == 0 ? "e" : "e same");
  }
}
