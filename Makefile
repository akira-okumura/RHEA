TEX := platex
DVIPDFMX := dvipdfmx
EXTRACTBB := extractbb

TEXS := RHEA.tex $(wildcard tex/*.tex)
FIGS := $(wildcard fig/*)
SRCS := $(wildcard src/*)

PDFS := $(wildcard fig/*pdf)
PNGS := $(wildcard fig/*png)
XBBS := $(patsubst %.pdf,%.xbb,$(PDFS)) $(patsubst %.png,%.xbb,$(PNGS))

TEXS := $(filter-out *~ tex/*~, $(TEXS))
FIGS := $(filter-out fig/*~, $(FIGS))
SRCS := $(filter-out src/*~, $(SRCS))

.PHONY: all clean xbb

all: RHEA.pdf

xbb: $(XBBS)

%.xbb: %.pdf
	$(EXTRACTBB) $<

%.xbb: %.png
	$(EXTRACTBB) $<

RHEA.dvi: $(TEXS) $(FIGS) $(SRCS) xbb
	$(TEX)	$^
	(while egrep '^LaTeX Warning: Label' RHEA.log;\
		do platex $^;\
	done)

RHEA.pdf: RHEA.dvi
	$(DVIPDFMX) $^

clean:
	rm -f RHEA.pdf RHEA.dvi RHEA.aux RHEA.log RHEA.out RHEA.toc tex/*.aux *~ src/*~ tex/*~
