import ROOT

def population():
    global hist, can, leg
    fin = open('population.dat')

    kBinsN = 21
    hist = []

    names = fin.readline().split('\t')

    for i in range(len(names)):
        hist.append(ROOT.TH1D(names[i], names[i], kBinsN, 0, 105))

    for i, line in enumerate(fin.readlines()):
        data = line.split('\t')
        for j in range(len(hist)):
            hist[j].SetBinContent(i + 1, float(data[j]))
   
    can = ROOT.TCanvas('can', 'histogram')
    can.DrawFrame(0, 0, 105, 10, 'Population by Age;Age;Population per 5-year Generation (%/5 year)')

    leg = ROOT.TLegend(0.65, 0.7, 0.85, 0.85)
    leg.SetFillStyle(0)

    kColor = (ROOT.kGray + 1, ROOT.kRed - 4, ROOT.kBlue - 4)

    for i in range(len(names)):
        hist[i].Scale(100./hist[i].GetEffectiveEntries())
        hist[i].SetLineColor(kColor[i])
        hist[i].SetFillColor(kColor[i])
        hist[i].SetBarWidth(0.28)
        hist[i].SetBarOffset(0.08 + 0.28*i)
        hist[i].Draw('bar same')
        leg.AddEntry(hist[i], hist[i].GetTitle(), 'f')

    leg.Draw()
