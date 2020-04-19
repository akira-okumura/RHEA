TEX := uplatex
BIB := pbibtex
DVIPDFMX := dvipdfmx
EXTRACTBB := extractbb

NAME := RHEA
TEXS := $(NAME).tex $(wildcard tex/*.tex)
FIGS := $(wildcard fig/*)
SRCS := $(wildcard src/*)
BBL  := $(NAME).bbl

PDFS := $(wildcard fig/*pdf)
PNGS := $(wildcard fig/*png)
XBBS := $(patsubst %.pdf, %.xbb, $(PDFS)) $(patsubst %.png, %.xbb, $(PNGS))

FIGS := $(filter-out fig/*~, $(FIGS))
SRCS := $(filter-out src/*~, $(SRCS))

.PHONY: all clean

all: $(NAME).pdf

%.xbb: %.pdf
	$(EXTRACTBB) $<

%.xbb: %.png
	$(EXTRACTBB) $<
%.aux: %.tex
	$(TEX) $(NAME)

$(BBL): $(NAME).aux $(NAME).bib $(NAME).bst
	$(BIB) $(NAME)

$(NAME).dvi: $(TEXS) $(FIGS) $(SRCS) $(XBBS) $(BBL)
	$(TEX)	$(NAME)
	(while egrep '^LaTeX Warning: Label' $(NAME).log;\
		do $(TEX) $(NAME);\
	done)

$(NAME).pdf: $(NAME).dvi
	$(DVIPDFMX) $^

clean:
	rm -f $(NAME).pdf $(NAME).dvi $(NAME).aux $(NAME).log $(NAME).out $(NAME).toc $(NAME).bbl $(NAME).blg tex/*.aux *~ src/*~ tex/*~ $(XBBS)
