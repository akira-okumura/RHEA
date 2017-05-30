void dice() {
  gStyle->SetOptStat();

  const Int_t kNthrow = 100000;
  const Int_t kNgraph = 10000;
  const Int_t kNgraphDrawn = 100;
  TGraph *graph[kNgraphDrawn];

  const Int_t kNhist = 6;
  TH1D *hist[kNhist];
  const Double_t kXmin[kNhist] = {0, 1.5, 2.7, 3.3, 3.42, 3.48};
  const Double_t kXmax[kNhist] = {7, 5.5, 4.3, 3.7, 3.58, 3.52};
  const Double_t kNbins[kNhist] = {100, 80, 80, 80, 80, 80};

  for (Int_t i = 0; i < kNhist; ++i) {
    Double_t w = (kXmax[i] - kXmin[i]) / kNbins[i];
    hist[i] = new TH1D(Form("h%d", i), Form("#it{n} = %.0f;Sample Mean;Entries",
                                            TMath::Power(10, i)),
                       kNbins[i], kXmin[i] - w / 2., kXmax[i] - w / 2.);
  }

  TCanvas *can = new TCanvas("can1", "can1");
  can->DrawFrame(1, 0, kNthrow, 7,
                 ";Number of Throws (Sample Size);Sample Mean");
  can->SetLogx();

  TCanvas *can2 = new TCanvas("can2", "can2");
  can2->Divide(3, 2, 1e-10, 1e-10);

  can->cd();

  TNtuple *nt = new TNtuple("nt", "", "x");

  for (Int_t i = 0; i < kNgraph; ++i) {
    Long64_t total = 0;
    if (i < kNgraphDrawn) {
      graph[i] = new TGraph;
    }
    for (Int_t j = 0; j < kNthrow; ++j) {
      total += TMath::Floor(gRandom->Uniform(1, 7));
      Int_t ntrials = j + 1;
      Double_t mean = Double_t(total) / ntrials;
      if (i < kNgraphDrawn) {
        Int_t n = graph[i]->GetN();
        if (n <= 100 ||
            (n > 100   && ntrials%10 == 0) ||
            (n > 1000  && ntrials%100 == 0) ||
            (n > 10000 && ntrials%1000 == 0)) {
          graph[i]->SetPoint(n, ntrials, mean);
        }
      }

      Double_t eps = 1e-5; // to avoid rounding error
      if (ntrials == 1) {
        hist[0]->Fill(mean + eps);
      } else if (ntrials == 10) {
        hist[1]->Fill(mean + eps);
      } else if (ntrials == 100) {
        hist[2]->Fill(mean + eps);
        nt->Fill(mean + 1e-5);
      } else if (ntrials == 1000) {
        hist[3]->Fill(mean + eps);
      } else if (ntrials == 10000) {
        hist[4]->Fill(mean + eps);
      } else if (ntrials == 100000) {
        hist[5]->Fill(mean + eps);
      }
    }
    if (i < kNgraphDrawn) {
      graph[i]->Draw("l same");
    }
  }

  for (Int_t i = 0; i < kNhist; ++i) {
    can2->cd(i + 1);
    hist[i]->Draw();
  }
}
