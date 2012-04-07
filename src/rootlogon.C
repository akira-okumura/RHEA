{
  // You MUST do the following settings regardless of your taste
  gROOT->SetStyle("Plain"); // Set the overall design to "Plain" mode
  gStyle->SetTitleBorderSize(0); // Remove the boarder from title panels
  gStyle->SetFrameFillColor(0); // Set the frame color to white
  gStyle->SetCanvasColor(0); // Set the canvas color to white
  gStyle->SetPadBorderSize(0); // Remove uneccesary margin in pads
  gStyle->SetPalette(1); // Rainbow color palette

  // Change the default position of titles to top-center (optional)
  gStyle->SetTitleAlign(22);
  gStyle->SetTitleX(0.5);
  gStyle->SetTitleY(0.95);

  // Show the ticks on right Y axes and top X axes (optional)
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);

  // Set the default font to Times (optional)
  Int_t fontid = 132;
  gStyle->SetStatFont(fontid);
  gStyle->SetLabelFont(fontid, "XYZ");
  gStyle->SetLabelFont(fontid, "");
  gStyle->SetTitleFont(fontid, "XYZ");
  gStyle->SetTitleFont(fontid, "");
  gStyle->SetTitleOffset(1.2, "XYZ");
  gStyle->SetTextFont(fontid);

  gStyle->SetFuncWidth(2); // Set the default line width of functions to 2
  gStyle->SetLegendBorderSize(0); // Remove the legend boarder
}
