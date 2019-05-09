import ROOT

def Cs137(xmin=2400, xmax=3100):
    #xmin, xmax = 2300, 3200 # 1.654e-26
    #xmin, xmax = 2400, 3100 # 9.793e-7
    #xmin, xmax = 2500, 3000 # 0.06219
    global h, can, f, pad, res
    h = ROOT.TH1I('h', ';ADC Channel;Counts', 4096, -0.5, 4095.5)

    reading_header = True
    for line in open('Cs137.dat').readlines():
        if reading_header:
            if line == '  chn  ,  data\n':
                reading_header = False
        else:
            ch, counts = [int(x) for x in line[:-1].split(',')]
            h.SetBinContent(h.GetBin(ch), counts)

    can = ROOT.TCanvas('can', 'can')
    can.cd(1).SetBottomMargin(0.3)
    h.SetMinimum(0.2)
    h.SetMaximum(20000)
    h.GetXaxis().SetLabelSize(0)
    h.Draw('e')

    ROOT.gPad.SetLogy()

    f = ROOT.TF1('f', 'pol1 + gaus(2)')
    f.SetParameter(0, 10)
    f.SetParameter(1, -1)
    f.SetParameter(2, 10000)
    f.SetParameter(3, 2700)
    f.SetParameter(4, 100)
    h.Fit(f, 'i', '', xmin, xmax)

    pad = ROOT.TPad('pad', 'pad', 0., 0., 1., 1.)
    pad.SetTopMargin(0.7)
    pad.SetFillColor(0)
    pad.SetFillStyle(0)
    pad.Draw()

    res = ROOT.TGraphErrors()

    for x in range(xmin, xmax):
        b = h.GetXaxis().FindBin(x)
        ex = 0
        y = f.Eval(x)
        ey = h.GetBinError(b)/y
        y = (h.GetBinContent(b) - y)/y
        res.SetPoint(res.GetN(), x, y)
        res.SetPointError(res.GetN() - 1, ex, ey)

    pad.cd(0)
    bmin, bmax = h.GetXaxis().GetXmin(), h.GetXaxis().GetXmax()
    res.GetXaxis().SetLimits(bmin, bmax)
    res.GetHistogram().SetMaximum(0.5)
    res.GetHistogram().SetMinimum(-0.5)
    res.GetYaxis().SetNdivisions(104, 0)
    res.GetYaxis().CenterTitle()
    res.SetTitle(';ADC;#chi')
    res.Draw('ape')

    print('Prob. = %.3e' % ROOT.TMath.Prob(f.GetChisquare(), f.GetNDF()))
