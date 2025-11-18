СС = gcc
CF = -Wall -Wextra -Werror -std=c11 -pedantic -g -Wno-gnu-zero-variadic-macro-arguments
FLAGS = -lcheck -lm
GCOV = -fprofile-arcs -ftest-coverage


all: s21_matrix.a

s21_matrix.a : s21_matrix.o s21_utils.o 
	ar rcs s21_matrix.a s21_matrix.o s21_utils.o 

s21_matrix.o: s21_matrix.c
	$(CC) $(CF) -c s21_matrix.c

s21_utils.o: s21_utils.c
	$(CC) $(CF) -c s21_utils.c

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

test: s21_matrix_gcov s21_utils_gcov 
	$(CC) $(CF) $(GCOV) tests/*.c s21_matrix_gcov s21_utils_gcov -o all_tests $(FLAGS)
	./all_tests

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	open out/index.html

valgrind_test: test
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./all_tests > valgrind_summary.txt 2>&1 
	grep "ERROR SUMMARY:" valgrind_summary.txt

s21_matrix_gcov: s21_matrix.c
	$(CC) $(CF) $(GCOV) -c s21_matrix.c -o s21_matrix_gcov

s21_utils_gcov : s21_utils.c
	$(CC) $(CF) $(GCOV) -c s21_utils.c -o s21_utils_gcov 

clean:
	rm -rf *.o tests/*.o *.a *.gc* all_tests out *.html *.info *.out *gcov all_tests.dSYM valgrind_summary.txt 
