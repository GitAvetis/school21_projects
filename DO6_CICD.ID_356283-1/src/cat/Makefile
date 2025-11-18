SHELL := /bin/bash
CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11 -pedantic

all: s21_cat 
rebuild: clean all

s21_cat : s21_cat.o s21_files_io.o
	$(CC) $(FLAGS) s21_cat.o s21_files_io.o -o s21_cat

s21_cat.o : s21_cat.c
	$(CC) $(FLAGS) -c s21_cat.c

s21_files_io.o : s21_files_io.c
	$(CC) $(FLAGS) -c s21_files_io.c
gnu:
	-diff <(./s21_cat -T test_files/test_1_cat.txt) <(cat -T test_files/test_1_cat.txt)
	-diff <(./s21_cat -E test_files/test_1_cat.txt) <(cat -E test_files/test_1_cat.txt)
	-diff <(./s21_cat --number-nonblank test_files/test_1_cat.txt) <(cat --number-nonblank test_files/test_1_cat.txt)
	-diff <(./s21_cat --squeeze-blank test_files/test_1_cat.txt) <(cat --squeeze-blank test_files/test_1_cat.txt)
	-diff <(./s21_cat --number test_files/test_1_cat.txt) <(cat --number test_files/test_1_cat.txt)
	
tests: 
	-diff <(./s21_cat -v test_files/test_5_cat.txt) <(cat -v test_files/test_5_cat.txt)
	-diff <(./s21_cat -n test_files/test_1_cat.txt) <(cat -n test_files/test_1_cat.txt)
	-diff <(./s21_cat -t test_files/test_3_cat.txt) <(cat -t test_files/test_3_cat.txt)
	-diff <(./s21_cat -n test_files/test_2_cat.txt) <(cat -n test_files/test_2_cat.txt)
	-diff <(./s21_cat -n -b test_files/test_1_cat.txt) <(cat -n -b test_files/test_1_cat.txt)
	-diff <(./s21_cat -s -n -e test_files/test_4_cat.txt) <(cat -s -n -e test_files/test_4_cat.txt)
	-diff <(./s21_cat -n test_files/test_1_cat.txt test_files/test_2_cat.txt) <(cat -n test_files/test_1_cat.txt test_files/test_2_cat.txt)
	


check: leaks cppcheck 
	clang-format -n *.h *.c

clang:
	clang-format -i *.h *.c

cppcheck:
	 cppcheck --enable=all --suppress=missingIncludeSystem --check-level=exhaustive --checkers-report=cpplog *c  

leaks:
	leaks -atExit -- ./s21_cat -b -e -n -s -t -v test_files/test_1_cat.txt
	leaks -atExit -- ./s21_cat -t test_files/test_3_cat.txt
	leaks -atExit -- ./s21_cat -s -n -e test_files/test_4_cat.txt
	leaks -atExit -- ./s21_cat -n test_files/test_1_cat.txt test_files/test_2_cat.txt    
clean : 
	rm -rf *.o *.a *.so *.out s21_cat cpplog

