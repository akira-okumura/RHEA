void population() {
  std::ifstream fin("population.dat");

  const Int_t kHistN = 3;
  const Int_t kBinsN = 21;
  TH1D* hist[kHistN];

  for (Int_t i = 0; i < kHistN; ++i) {
    std::string str;
    fin >> str;
    hist[i] = new TH1D(str.c_str(), str.c_str(), kBinsN, 0, 105);
  }

  for (Int_t j = 0; j < kBinsN; ++j) {
    for (Int_t i = 0; i < kHistN; ++i) {
      Int_t pop;
      fin >> pop;
      hist[i]->SetBinContent(j + 1, pop);
    }
  }

  TCanvas* can1 = new TCanvas("can1", "histogram");

  TH1D* frame = new TH1D(
      "frame",
      "Population by Age;Age;Population per 5-year Generation (%/5 year)",
      kBinsN, 0, 105);
  frame->SetMaximum(10);
  frame->Draw();

  TLegend* leg1 = new TLegend(0.65, 0.7, 0.85, 0.85);
  leg1->SetFillStyle(0);

  Int_t kColor[kHistN] = {kGray + 1, kRed - 4, kBlue - 4};

  for (Int_t i = 0; i < kHistN; ++i) {
    hist[i]->Scale(100. / hist[i]->GetEffectiveEntries()); // normalize
    hist[i]->SetLineColor(kColor[i]);
    hist[i]->SetFillColor(kColor[i]);
    hist[i]->SetBarWidth(0.28);
    hist[i]->SetBarOffset(0.08 + 0.28 * i);
    hist[i]->Draw("bar same");
    leg1->AddEntry(hist[i], hist[i]->GetTitle(), "f");
  }
  leg1->Draw();

  TCanvas* can2 = new TCanvas("can2", "graph");
  frame->Draw();
  TGraph* graph[kHistN];
  TLegend* leg2 = new TLegend(0.65, 0.7, 0.85, 0.85);
  leg2->SetFillStyle(0);

  for (Int_t i = 0; i < kHistN; ++i) {
    graph[i] = new TGraph();
    for (Int_t j = 0; j < kBinsN; ++j) {
      graph[i]->SetPoint(j, hist[i]->GetBinCenter(j + 1),
                         hist[i]->GetBinContent(j + 1));
    }
    graph[i]->SetLineColor(kColor[i]);
    graph[i]->SetMarkerColor(kColor[i]);
    graph[i]->Draw("same");
    leg2->AddEntry(graph[i], hist[i]->GetTitle(), "l");
  }
  leg2->Draw();
}
