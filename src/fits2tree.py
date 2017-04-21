#!/usr/bin/env python

import numpy
from astropy.io import fits
import ROOT

def addBranch(tree, column):
    fits2numpy = {'E':numpy.float32, # float
                  'D':numpy.float64, # double
                  'I':numpy.int16, # short
                  'J':numpy.int32, # int
                  'X':numpy.bool_} # bool
    fits2root  = {'E':'F', # float
                  'D':'D', # double
                  'I':'S', # short
                  'J':'I', # int
                  'X':'O'} # bool

    name = column.name
    form = column.format
    unit = column.unit

    if name == "CALIB_VERSION":
        arr = numpy.zeros(3, dtype = fits2numpy[form[-1]])
    elif name in ("EVENT_CLASS", "EVENT_TYPE"):
        arr = numpy.zeros(32, dtype = fits2numpy[form[-1]])
    else:
        arr = numpy.zeros(1, dtype = fits2numpy[form])

    n = len(arr)
    if n == 0:
        tree.Branch(name, arr, '%s/%s' % (name, fits2root[form]))
    else:
        tree.Branch(name, arr, '%s[%d]/%s' % (name, n, fits2root[form[-1]]))

    return arr

def main(input_fits_file, output_root_file):
    print("Opening %s..." % input_fits_file)

    tree = ROOT.TTree("photons", "LAT PASS8 Photons")    
    hdulist = fits.open(input_fits_file)
    events = hdulist[1]
    arrays = []

    for col in events.columns:
        arrays.append(addBranch(tree, col))

    nevents = events.header['NAXIS2']
    data = events.data
    fill = tree.Fill

    for i in xrange(nevents):
        event = data[i]
        if i%100 == 0:
            print i
        #for arr in zip(arrays):
        #for col in zip(event):
        for col in event:
        #for arr, col in zip(arrays, event):
            pass
        #    arr[:] = col

        fill()

    f = ROOT.TFile(output_root_file, "recreate")
    tree.Write()
    f.Close()

import sys
        
if __name__ == "__main__":
    argv = sys.argv

    input_fits_file = argv[1]
    output_root_file = argv[2]
    
    main(input_fits_file, output_root_file)


