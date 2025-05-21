# Имя LaTeX-документа (без .tex)
DOC = paper

# Каталоги с данными и графиками
DATA_DIR = data
FIGURES_DIR = figures

# Имена файлов
TEX_FILE = $(DOC).tex
PDF_FILE = $(DOC).pdf

# Найти все файлы .dat в каталоге data
DATA_FILES = $(wildcard $(DATA_DIR)/*.dat)

# Сформировать список имен файлов графиков на основе файлов данных
FIGURES = $(patsubst $(DATA_DIR)/%.dat,$(FIGURES_DIR)/%.png,$(DATA_FILES))

# Цель по умолчанию: создать PDF
all: $(PDF_FILE)

# Правило для создания PDF из TeX-файла
$(PDF_FILE): $(TEX_FILE) $(FIGURES)
	pdflatex $(TEX_FILE)
	pdflatex $(TEX_FILE)

# Правило для создания графиков из файлов данных
$(FIGURES_DIR)/%.png: $(DATA_DIR)/%.dat
	@mkdir -p $(FIGURES_DIR)
	python3 plot.py $< $@  # Явно вызываем python3

# Правило для очистки сгенерированных файлов
clean:
	rm -f *.aux *.log *.pdf *.dvi *.toc *.bbl *.blg *.synctex.gz
	rm -rf $(FIGURES_DIR)
