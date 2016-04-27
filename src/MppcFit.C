void MppcFit() {
  TFile file("../misc/MPPC.root");
  gROOT->cd();
  TH1* h = (TH1*)file.Get("pulseheight")->Clone();
  file.Close();

  const Double_t kRoughHeight = 16.5/9.; // ~16.5 (mV) at 9 p.e.
  const Int_t kNPeaks = 6;
  TF1* gaus[kNPeaks];

  std::string fit_string = "";

  for(Int_t i = 0; i < kNPeaks; ++i){
    gaus[i] = new TF1(Form("g%d",  i), "gaus", (i + 0.6)*kRoughHeight, (i + 1.4)*kRoughHeight);
    gaus[i]->SetLineColor(i + 2);
    gaus[i]->SetLineStyle(2);

    if (i != 0) {
      fit_string += "+";
    }
    fit_string += Form("gaus(%d)", i*3);
  }

  TF1* total = new TF1("total", fit_string.c_str(), 1., 17.);
  total->SetLineWidth(1);
  total->SetLineStyle(1);
  total->SetNpx(1000);

  for(Int_t i = 0; i < kNPeaks; ++i) {
    h->Fit(gaus[i], i == 0 ? "R" : "R+");
    for(Int_t j = 0; j < 3; ++j) {
      Double_t p = gaus[i]->GetParameter(j);
      total->SetParameter(i*3 + j, p);
      if(j == 1) {
        total->SetParLimits(i*3 + j, p - 0.5, p + 0.5);
      } else if(j == 2) {
        total->SetParLimits(i*3 + j, p*0.5, p*1.5);
      }
      h->Fit(total, "R+");
    }
  }

  h->Fit(total, "i");
  
  h->Draw();
  h->GetXaxis()->SetRangeUser(0, 15);

  for(Int_t i = 0; i < kNPeaks; ++i) {
    for(Int_t j = 0; j < 3; ++j) {
      Double_t p = total->GetParameter(i*3 + j);
      gaus[i]->SetParameter(j, p);
    }
    gaus[i]->Draw("l same");      
  }
}
