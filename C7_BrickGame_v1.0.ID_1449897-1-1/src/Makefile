CC = gcc
CFLAGS =  -Wall -Wextra -Werror -std=c11 -pedantic -g
LDFLAGS = -lncurses
CHECKFLAGS = -pthread -lcheck -lm

SRC_DIR = brick_game/tetris
GUI_DIR = gui/cli
TEST_SRC = tests/*.c

SRC = $(SRC_DIR)/backend.c $(GUI_DIR)/front.c
TARGET = tetris


DOXYGEN = doxygen
DOC_DIR = docs
OPEN_CMD = open

DIST_NAME = tetris-1.0
DIST_DIR = dist

all: clean tetris

tetris: $(SRC)
	$(CC) $(CFLAGS) -o tetris $(SRC) $(LDFLAGS)

test: tetris_test.a
	$(CC) --coverage $(TEST_SRC) -o test_runner tetris_test.a $(CHECKFLAGS)
	./test_runner

tetris_test.a:
	$(CC) -c $(CFLAGS) --coverage $(SRC_DIR)/backend.c
	ar rcs tetris_test.a *.o
	rm -f *.o

memory: clean tetris
	leaks -atExit -- ./tetris 

memory_test: clean tetris_test.a
	$(CC) --coverage $(TEST_SRC) -o test_runner tetris_test.a $(CHECKFLAGS) 
	leaks -atExit -- ./test_runner 

cppcheck:  
	cppcheck --enable=all --std=c11 --check-level=exhaustive --disable=information --suppress=missingIncludeSystem --suppress=missingInclude --suppress=checkersReport tests brick_game/tetris gui/cli 

install: clean tetris
	cp tetris /usr/local/bin/tetris

uninstall:
	-rm -f /usr/local/bin/tetris /usr/local/bin/tetris_score.txt
	make clean

dvi: 
	@echo "Generating HTML documentation..."
	@if ! command -v $(DOXYGEN) >/dev/null 2>&1; then \
		echo "Error: Doxygen is not installed!"; \
		echo "Install it with: brew install doxygen"; \
		exit 1; \
	fi
	$(DOXYGEN) Doxyfile 2>/dev/null
	@echo "HTML documentation generated: $(DOC_DIR)/html/index.html"
	@if command -v $(OPEN_CMD) >/dev/null 2>&1; then \
		$(OPEN_CMD) $(DOC_DIR)/html/index.html; \
	else \
		echo "Cannot open browser. Please open manually: $(DOC_DIR)/html/index.html"; \
	fi

dist:
	mkdir -p $(DIST_DIR)/$(DIST_NAME)
	cp -r brick_game gui tests $(DIST_DIR)/$(DIST_NAME)/
	cp Makefile Doxyfile FSM.png $(DIST_DIR)/$(DIST_NAME)/
	tar -czf $(DIST_DIR)/$(DIST_NAME).tar.gz -C $(DIST_DIR) $(DIST_NAME)
	cd $(DIST_DIR) && zip -r $(DIST_NAME).zip $(DIST_NAME)/
	@echo "Дистрибутив создан"

gcov_report: test
	rm -rf gcov_report
	mkdir -p gcov_report
	gcov -r backend.gcda
	geninfo --no-external --output-file coverage.info .
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/brick_game/tetris/index.html
	rm -f tetris test_runner tetris_lib.a tetris_test.a *.o *.gcno *.gcda *.gcov coverage.info

clean:
	rm -f tetris tetris_score.txt 
	rm -rf gcov_report tetris.dSYM $(DOC_DIR) $(DIST_DIR)
	rm -f build/tetris test_runner tetris_lib.a tetris_test.a *.o *.gcno *.gcda *.gcov coverage.info

run: tetris
	./tetris