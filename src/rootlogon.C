{
  // Recommended color settings for color vision deficiency
  gStyle->SetPalette(kBird);   // Default in recent ROOT, but just in case.

  // 0 : White, 1 : K,  2 : R,  3 : G,
  // 4 : B,     5 : C,  6 : M,  7 : Y
  // Avoid bright yellow and green for better presentation.
  gROOT->GetColor(3)->SetRGB(0., .7, 0.); // Green  (0., 1., 0.)->(0.,  .7,  0.)
  gROOT->GetColor(5)->SetRGB(1., .5, 0.); // Yellow (0., 1., 0.)->(0.,  .7,  0.)
  gROOT->GetColor(7)->SetRGB(.2, .6, .6); // Cyan   (.4, 1., 1.)->(.25,.25, .75)
 
  // Okumura's preference
  gStyle->SetPadBorderSize(0); // Remove uneccesary margin in pads
  gStyle->SetFuncWidth(2); // Set the default line width of functions to 2
  gStyle->SetLegendBorderSize(0); // Remove the legend boarder

  // Change the default position of titles to top-center (optional)
  gStyle->SetTitleAlign(22);
  gStyle->SetTitleX(0.5);
  gStyle->SetTitleY(0.95);

  // Show the ticks on right Y axes and top X axes (optional)
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);

  // Set the default font to Times (optional)
  // This is optional, but recommended if you mix TLatex
  Int_t fontid = 132;
  gStyle->SetStatFont(fontid);
  gStyle->SetLabelFont(fontid, "XYZ");
  gStyle->SetLabelFont(fontid, "");
  gStyle->SetTitleFont(fontid, "XYZ");
  gStyle->SetTitleFont(fontid, "");
  gStyle->SetTitleOffset(1.2, "XYZ");
  gStyle->SetTextFont(fontid);
  gStyle->SetLegendFont(fontid);
}
