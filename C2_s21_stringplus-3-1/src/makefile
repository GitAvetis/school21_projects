СС = gcc
CF = -Wall -Wextra -Werror -std=c11 -pedantic -g
FLAGS = -lcheck -lm -lsubunit
GCOV = -fprofile-arcs -ftest-coverage


all: s21_string.a

s21_string.a : s21_sscanf.o s21_sprintf.o s21_string.o
	ar rcs s21_string.a s21_sscanf.o s21_sprintf.o s21_string.o -o s21_string.a

s21_string.o: s21_string.c
	$(CC) $(CF) -c s21_string.c

s21_sprintf.o: s21_sprintf.c
	$(CC) $(CF) -c s21_sprintf.c

s21_sscanf.o: s21_sscanf.c
	$(CC) $(CF) -c s21_sscanf.c

clang-format:
	cp ../materials/linters/.clang-format .clang-format
	cp ../materials/linters/.clang-format tests/.clang-format
	clang-format -i *.c *.h
	clang-format -n *.c *.h
	clang-format -i ./tests/*.c ./tests/*.h
	clang-format -n ./tests/*.c ./tests/*.h
	rm -rf .clang-format tests/.clang-format

cppcheck: 
	cppcheck --enable=all --suppress=missingIncludeSystem *.c tests/*.c

test: s21_string_gcov s21_sprintf_gcov s21_sscanf_gcov
	$(CC) $(CF) $(GCOV) tests/*.c s21_string_gcov s21_sprintf_gcov s21_sscanf_gcov -o all_tests $(FLAGS)
	./all_tests

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	xdg-open out/index.html

valgrind_test: test
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./all_tests > valgrind_summary.txt 2>&1 
	grep "ERROR SUMMARY:" valgrind_summary.txt

s21_string_gcov: s21_string.c
	$(CC) $(CF) $(GCOV) -c s21_string.c -o s21_string_gcov

s21_sprintf_gcov: s21_sprintf.c
	$(CC) $(CF) $(GCOV) -c s21_sprintf.c -o s21_sprintf_gcov

s21_sscanf_gcov: s21_sscanf.c
	$(CC) $(CF) $(GCOV) -c s21_sscanf.c -o s21_sscanf_gcov

clean:
	rm -rf *.o tests/*.o *.a *.gc* all_tests out *.html *.info *.out *gcov valgrind_summary.txt
