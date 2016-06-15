#!/usr/bin/env python
import ROOT
import numpy

def tree_extract(input_name, output_name):
    fin = ROOT.TFile(input_name)
    photons = fin.Get('photons')

    energy = numpy.ndarray(1, dtype = 'float32')
    l = numpy.ndarray(1, dtype = 'float32')
    b = numpy.ndarray(1, dtype = 'float32')

    fout = ROOT.TFile(output_name, 'create')
    photons_mod = ROOT.TTree('photons', '')
    photons_mod.Branch('ENERGY', energy, 'ENERGY/F')
    photons_mod.Branch('L', l, 'L/F')
    photons_mod.Branch('B', b, 'B/F')

    for i in xrange(photons.GetEntries()):
        photons.GetEntry(i)
        energy[0] = photons.ENERGY
        l[0] = photons.L
        b[0] = photons.B
        zenith = photons.ZENITH_ANGLE
        if zenith < 100.:
            photons_mod.Fill()

    photons_mod.Write()
    fout.Close()

import sys

if __name__ == '__main__':
    argv = sys.argv

    input_name = argv[1]
    output_name = argv[2]
    
    tree_extract(input_name, output_name)

