TCanvas* ExactSizeCanvas(const char* name, const char* title, Double_t width,
                         Double_t height) {
  TCanvas* can = new TCanvas(name, title, width, height);
  can->SetWindowSize(width + (width - can->GetWw()),
                     height + (height - can->GetWh()));
  gSystem->ProcessEvents();

  return can;
}
