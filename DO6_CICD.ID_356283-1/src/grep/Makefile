SHELL := /bin/bash
FLAG = -Wall -Wextra -Werror -std=c11 -pedantic
FILE = test.txt test2.txt
PATTERNS = patterns.txt 
ERROR = ERROR

all: s21_grep 

s21_grep : s21_grep.o s21_grep_io.o
	$(CC) $(FLAGS) s21_grep.o s21_grep_io.o -o s21_grep

s21_grep.o : s21_grep.c
	$(CC) $(FLAGS) -c s21_grep.c

s21_grep_io.o : s21_grep_io.c
	$(CC) $(FLAGS) -c s21_grep_io.c

tests:
	diff <(./s21_grep He $(FILE)) <(grep He $(FILE))
	diff <(./s21_grep -e He -e he $(FILE)) <(grep -e He -e he $(FILE))
	diff <(./s21_grep -v He $(FILE)) <(grep -v He $(FILE))
	diff <(./s21_grep -c He $(FILE)) <(grep -c He $(FILE))
	diff <(./s21_grep -l He $(FILE)) <(grep -l He $(FILE))
	diff <(./s21_grep -n He $(FILE)) <(grep -n He $(FILE))
	diff <(./s21_grep -i He $(FILE)) <(grep -i He $(FILE))
	diff <(./s21_grep -h He $(FILE)) <(grep -h He $(FILE))
	diff <(./s21_grep -s he nofile) <(grep -s he nofile)
	diff <(./s21_grep -f $(PATTERNS) $(FILE)) <(grep -f $(PATTERNS) $(FILE))
	diff <(./s21_grep -iv He $(FILE)) <(grep -iv He $(FILE))
	diff <(./s21_grep -in He $(FILE)) <(grep -in He $(FILE))
	diff <(./s21_grep -in He $(FILE)) <(grep -in He $(FILE))
	diff <(./s21_grep -ie "^he" $(FILE)) <(grep -ie "^he" $(FILE))
	diff <(./s21_grep -ince "^he" $(FILE)) <(grep -ince "^he" $(FILE))
	diff <(./s21_grep -ih se $(FILE)) <(grep -ih se $(FILE))
	diff <(./s21_grep -hc e $(FILE)) <(grep -hc e $(FILE))
	diff <(./s21_grep -o -e he -e Se  $(FILE)) <(grep -o -e he -e Se  $(FILE))
	diff <(./s21_grep -oinc he $(FILE)) <(grep -oinc he $(FILE))

clang:
	clang-format -i *.h *.c
check: leaks cppcheck 
	clang-format -n *.h *.c

cppcheck:
	 cppcheck --enable=all --suppress=missingIncludeSystem --check-level=exhaustive --checkers-report=cpplog *c  
leaks:
	leaks -atExit -- ./s21_grep -ince "^he" test.txt test2.txt
	leaks -atExit -- ./s21_grep -e He -e he test.txt test2.txt
	leaks -atExit -- ./s21_grep -s he nofile
	leaks -atExit -- ./s21_grep -oinc he test.txt test2.txt

clean : 
	rm -rf *.o *.a *.so *.out s21_grep cpplog
