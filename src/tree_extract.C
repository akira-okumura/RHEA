void tree_extract(const char* input, const char* output) {
  TFile fin(input);
  TTree* photons = (TTree*)fin.Get("photons");
  Float_t energy, l, b, zenith;
  photons->SetBranchAddress("ENERGY", &energy);
  photons->SetBranchAddress("L", &l);
  photons->SetBranchAddress("B", &b);
  photons->SetBranchAddress("ZENITH_ANGLE", &zenith);

  TFile fout(output, "create");
  TTree photons_mod("photons", "");
  photons_mod.Branch("ENERGY", &energy, "ENERGY/F");
  photons_mod.Branch("L", &l, "L/F");
  photons_mod.Branch("B", &b, "B/F");

  for(int i = 0; i < photons->GetEntries(); ++i) {
    photons->GetEntry(i);
    if (zenith < 100.) {
      photons_mod.Fill();
    }
  }

  photons_mod.Write();
  fout.Close();
}
