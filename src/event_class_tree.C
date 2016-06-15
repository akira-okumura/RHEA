#include "TTree.h"
#include "TFile.h"

class PhotonEvent : public TObject {
private:
  Float_t fEnergy;
  Float_t fL;
  Float_t fB;
  Float_t fZenithAngle;
  Short_t fCalibVersion[3];

public:
  void SetEnergy(Float_t energy) {fEnergy = energy;}
  void SetL(Float_t l) {fL = l;}
  void SetB(Float_t b) {fB = b;}
  void SetZenithAngle(Float_t zenith) {fZenithAngle = zenith;}
  void SetCalibVersion(Short_t* calib) {
    for(int i = 0; i < 3; ++i) {
      fCalibVersion[i] = calib[i];
    }
  }

  ClassDef(PhotonEvent, 1)
};

void event_class_tree(const char* input, const char* output) {
  TFile fin(input);
  TTree* photons = (TTree*)fin.Get("photons");
  Float_t energy, l, b, zenith;
  Short_t calib[3];
  photons->SetBranchAddress("ENERGY", &energy);
  photons->SetBranchAddress("L", &l);
  photons->SetBranchAddress("B", &b);
  photons->SetBranchAddress("ZENITH_ANGLE", &zenith);
  photons->SetBranchAddress("CALIB_VERSION", calib);

  PhotonEvent event;

  TFile fout(output, "create");
  TTree photons_mod("photons", "");
  photons_mod.Branch("event", "PhotonEvent", &event, 16000, 0);

  for(int i = 0; i < photons->GetEntries(); ++i) {
    photons->GetEntry(i);
    event.SetEnergy(energy);
    event.SetL(l);
    event.SetB(b);
    event.SetZenithAngle(zenith);
    event.SetCalibVersion(calib);
    photons_mod.Fill();
  }

  photons_mod.Write();
  fout.Close();
}
