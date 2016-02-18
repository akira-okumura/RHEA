TEXS := RHEA.tex $(wildcard tex/*.tex)
FIGS := $(wildcard fig/*)
SRCS := $(wildcard src/*)

TEXS := $(filter-out *~ tex/*~, $(TEXS))
FIGS := $(filter-out fig/*~, $(FIGS))
SRCS := $(filter-out src/*~, $(SRCS))

.PHONY: all clean

all: RHEA.pdf

RHEA.dvi: $(TEXS) $(FIGS) $(SRCS)
	platex	$^
	(while egrep '^LaTeX Warning: Label' RHEA.log;\
		do platex $^;\
	done)

RHEA.pdf: RHEA.dvi
	dvipdfmx $^

clean:
	rm -f RHEA.pdf RHEA.dvi RHEA.aux RHEA.log RHEA.out RHEA.toc tex/*.aux *~ src/*~ tex/*~
