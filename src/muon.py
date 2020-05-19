import ROOT

N_CHANNELS = 8

def Q1_(fname):
    f = open(fname) # open the file
    lines = f.readlines() # read all the lines
    return lines # return as list
    
    # or just simply with 1 line
    # return open(fname).readlines()

def Q1(fname):
    '''
    A better version of Q1_
    '''
    try: # use the try/except clause to handle errors
        with open(fname) as f: # by using 'with', f is automatically closed
            print('Reading %s ...' % fname)
            return f.readlines() # don't do it if the file size is huge
    except FileNotFoundError as e: # your file name may be wrong
        print("No such file or directory: '%s'" % fname)
        return None
    except Exception as e: # other types of errors
        print("Cannot open '%s' (%s)" % (fname, e))
        return None

def Q2_(fname):
    lines = Q1_(fname) # get the return value of Q1_
    for line in lines: # do something line by line
        print(line[:-1]) # drop \n

def Q2(fname):
    '''
    A better version of Q1 and Q2_
    '''
    try:
        with open(fname) as f:
            print('Reading %s ...' % fname)
            for line in f: # more memory efficient way especially for huge files
                print(line[:-1])
    except FileNotFoundError as e:
        print("No such file or directory: '%s'" % fname)
    except Exception as e:
        print("Cannot open '%s' (%s)" % (fname, e))

def Q3_(fname):
    lines = Q1_(fname) # get the return value of Q1_
    
    for line in lines:
        values = line[:-1].split('\t') # drop \n
        t = values[0]
        unix_t = int(values[1])
        # counts = list(map(int, values[2:])) # either style is OK
        counts = [int(x) for x in values[2:]]
        print(t, unix_t, counts)

def Q3(fname):
    '''
    A better version of Q1 and Q3_
    '''
    try:
        with open(fname) as f:
            print('Reading %s ...' % fname)
            for line in f:
                try:
                    # Exception will raised if the format is incorrect
                    values = line[:-1].split('\t') # drop \n
                    t = values[0]
                    unix_t = int(values[1])
                    counts = [int(x) for x in values[2:]]

                    # it is possible that the file was closed before all the
                    # data was written to the disk
                    if len(counts) != N_CHANNELS:
                        raise # go to 'except'
                    print(t, unix_t, counts)
                except:
                    print("Incorrect data format found: '%s'" % line)
                    break # exit the for loop
    except FileNotFoundError as e:
        print("No such file or directory: '%s'" % fname)
    except Exception as e:
        print("Cannot open '%s' (%s)" % (fname, e))

def Q4_(fname):
    global hist, can

    lines = Q1_(fname)
    n = len(lines)

    hist = [ROOT.TH1D('h%d' % i, ';Time (hour);Entries / bin', n, 0, n) for i in range(N_CHANNELS)]
    
    for i, line in enumerate(lines):
        values = line[:-1].split('\t') # drop \n
        t = values[0]
        unix_t = int(values[1])
        counts = [int(x) for x in values[2:]]
        for j, count in enumerate(counts):
            binx = hist[j].Fill(i, count) # get the bin number
            hist[j].SetBinError(binx, count**0.5) # need manually set the bin error

    can = ROOT.TCanvas('can', 'can', 1600, 800)
    can.Divide(4, 2, 1e-10, 1e-10) # create 8 subpads
    for i in range(N_CHANNELS):
        can.cd(i + 1) # change the subpad location
        hist[i].Draw('e') # show error bars
            
def Q4(fname):
    '''
    A better version of Q1 and Q4_
    '''
    global hist, can
    hist = None
    
    try:
        with open(fname) as f:
            print('Reading %s ...' % fname)

            nlines = 0
            for line in f:
                try:
                    # Exception will raised if the format is incorrect
                    values = line[:-1].split('\t') # drop \n
                    t = values[0]
                    unix_t = int(values[1])
                    counts = [int(x) for x in values[2:]]

                    # it is possible that the file was closed before all the
                    # data was written to the disk
                    if len(counts) != N_CHANNELS:
                        raise # go to 'except'

                    if hist == None:
                        n = 150 # no good. should check the file length first
                        hist = [ROOT.TH1D('h%d' % i, ';Time (hour);Entries / bin', n, 0, n) for i in range(N_CHANNELS)]

                    for j, count in enumerate(counts):
                        binx = hist[j].Fill(nlines, count)
                        hist[j].SetBinError(binx, count**0.5)
                except:
                    print("Incorrect data format found: '%s'" % line)
                    break # exit the for loop
                finally:
                    nlines += 1
    except FileNotFoundError as e:
        print("No such file or directory: '%s'" % fname)
    except Exception as e:
        print("Cannot open '%s' (%s)" % (fname, e))

    can = ROOT.TCanvas('can', 'can', 1600, 800)
    can.Divide(4, 2, 1e-10, 1e-10)
    for i in range(N_CHANNELS):
        can.cd(i + 1)
        hist[i].Draw('e')
