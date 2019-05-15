import ROOT

def Cs137(xmin=2400, xmax=3100):
    #xmin, xmax = 2300, 3200 # 1.654e-26
    #xmin, xmax = 2400, 3100 # 9.793e-7
    #xmin, xmax = 2500, 3000 # 0.06219
    #xmin, xmax = 2600, 2900 # 0.1062
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

    can = ROOT.TCanvas('can', 'can', 1200, 600)
    can.Divide(2, 1)
    for i in range(2):
        can.cd(i + 1).SetBottomMargin(0.3)
        ROOT.gPad.SetLogy()
        h.SetMinimum(0.2)
        h.SetMaximum(20000)
        h.GetXaxis().SetLabelSize(0)
        if i == 0:
            h.Draw('e')
        else:
            frame = ROOT.gPad.DrawFrame(xmin - 100, h.GetMinimum(), xmax + 100, h.GetMaximum())
            frame.GetYaxis().SetTitle(h.GetYaxis().GetTitle())
            frame.GetXaxis().SetLabelSize(0)
            h.Draw('e same')

    f = ROOT.TF1('f', 'pol1 + gaus(2)')
    f.SetParameter(0, 10)
    f.SetParameter(1, -1)
    f.SetParameter(2, 10000)
    f.SetParameter(3, 2700)
    f.SetParameter(4, 100)
    h.Fit(f, 'i', '', xmin, xmax)

    pad = [ROOT.TPad('pad', 'pad', 0., 0., 1., 1.),
           ROOT.TPad('pad', 'pad', 0., 0., 1., 1.)]
    for i in range(2):
        pad[i].SetTopMargin(0.7)
        pad[i].SetFillColor(0)
        pad[i].SetFillStyle(0)
        can.cd(i + 1)
        pad[i].Draw()

    res = ROOT.TGraphErrors()

    for i, x in enumerate(range(xmin, xmax)):
        b = h.GetXaxis().FindBin(x)
        y = h.GetBinContent(b)
        f_y = f.Eval(x)
        ex = 0
        ey = h.GetBinError(b)
        dy = y - f_y
        res.SetPoint(i, x, dy/f_y)
        res.SetPointError(i, ex, ey/f_y)

    pad[0].cd()
    bmin, bmax = h.GetXaxis().GetXmin(), h.GetXaxis().GetXmax()
    res.GetXaxis().SetLimits(bmin, bmax)
    res.GetHistogram().SetMaximum(0.1)
    res.GetHistogram().SetMinimum(-0.1)
    res.GetYaxis().SetNdivisions(104, 0)
    res.GetYaxis().CenterTitle()
    res.SetTitle(';ADC;Rel. Residual')
    res.Draw('apez')

    frame = pad[1].cd().DrawFrame(xmin - 100, res.GetHistogram().GetMinimum(),
                                  xmax + 100, res.GetHistogram().GetMaximum())
    frame.GetYaxis().SetNdivisions(104, 0)
    frame.GetYaxis().CenterTitle()
    frame.SetTitle(';ADC;Rel. Residual')

    res.Draw('pez same')

    print('Prob. = %.3e' % ROOT.TMath.Prob(f.GetChisquare(), f.GetNDF()))
