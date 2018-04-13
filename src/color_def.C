void BPalette() {
  static const Int_t kN = 100;
  static Int_t colors[kN];
  static Bool_t initialized = kFALSE;

  Double_t r[] = {0., 0.0, 1.0, 1.0, 1.0};
  Double_t g[] = {0., 0.0, 0.0, 1.0, 1.0};
  Double_t b[] = {0., 1.0, 0.0, 0.0, 1.0};
  Double_t stop[] = {0., .25, .50, .75, 1.0};

  if (!initialized) {
    Int_t index = TColor::CreateGradientColorTable(5, stop, r, g, b, kN);
    for (int i = 0; i < kN; ++i) {
      colors[i] = index + i;
    }
    initialized = kTRUE;
  } else {
    gStyle->SetPalette(kN, colors);
  }
}

void GrayPalette() {
  static const Int_t kN = 100;
  static Int_t colors[kN];
  static Bool_t initialized = kFALSE;

  Double_t r[] = {0., 1.};
  Double_t g[] = {0., 1.};
  Double_t b[] = {0., 1.};
  Double_t stop[] = {0., 1.};

  if (!initialized) {
    Int_t index = TColor::CreateGradientColorTable(2, stop, r, g, b, kN);
    for (int i = 0; i < kN; ++i) {
      colors[i] = index + i;
    }
    initialized = kTRUE;
  } else {
    gStyle->SetPalette(kN, colors);
  }
}

void GrayInvPalette() {
  static const Int_t kN = 100;
  static Int_t colors[kN];
  static Bool_t initialized = kFALSE;

  Double_t r[] = {1., 0.};
  Double_t g[] = {1., 0.};
  Double_t b[] = {1., 0.};
  Double_t stop[] = {0., 1.};

  if (!initialized) {
    Int_t index = TColor::CreateGradientColorTable(2, stop, r, g, b, kN);
    for (int i = 0; i < kN; ++i) {
      colors[i] = index + i;
    }
    initialized = kTRUE;
  } else {
    gStyle->SetPalette(kN, colors);
  }
}

void RBPalette() {
  static const Int_t kN = 100;
  static Int_t colors[kN];
  static Bool_t initialized = kFALSE;

  Double_t r[] = {0., 1., 1.};
  Double_t g[] = {0., 1., 0.};
  Double_t b[] = {1., 1., 0.};
  Double_t stop[] = {0., .5, 1.};
  if (!initialized) {
    Int_t index = TColor::CreateGradientColorTable(3, stop, r, g, b, kN);
    for (int i = 0; i < kN; ++i) {
      colors[i] = index + i;
    }
    initialized = kTRUE;
  } else {
    gStyle->SetPalette(kN, colors);
  }
}
