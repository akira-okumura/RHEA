void WrongErrorEstimate(Double_t error = 1.0) {
  TGraphErrors* graph = new TGraphErrors;
  for (int i = 0; i < 10; ++i) {
    double x = i;
    double y = i + gRandom->Gaus(); // Add fluctuation with a sigma of 1
    double ex = 0;
    double ey = error;
    graph->SetPoint(i, x, y);
    graph->SetPointError(i, ex, ey);
  }

  graph->SetTitle(";x;y;");
  graph->SetMarkerStyle(20);
  graph->Draw("ap");

  gStyle->SetOptFit();
  graph->Fit("pol1");

  std::cout << "Probability = " << graph->GetFunction("pol1")->GetProb() << std::endl;
}
