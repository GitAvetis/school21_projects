СС = gcc
CF = -Wall -Wextra -Werror -std=c11 -pedantic -g
FLAGS = -lcheck -lm -lsubunit
GCOV = -fprofile-arcs -ftest-coverage

# Папки для сборки
BUILD_DIR = build
TEST_DIR = testbuild

# Поиск всех .c файлов в текущей директории
SRCS := $(wildcard *.c)

# Генерация имен объектных файлов
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
TSTS = $(SRCS:%.c=$(TEST_DIR)/%.o)

all: s21_decimal.a

# Основное правило для сборки статической библиотеки
s21_decimal.a: $(OBJS)
	ar rcs $@ $(OBJS) -o s21_decimal.a
	ranlib $@


# Правило для сборки объектных файлов
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CF) -c $< -o $@

$(TEST_DIR)/%.o: %.c | $(TEST_DIR)
	$(CC) $(CF) $(GCOV) -c $< -o $@


# Создание папки build, если она не существует
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TEST_DIR):
	mkdir -p $(TEST_DIR)


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

test: $(TSTS)
	$(CC) $(CF) $(GCOV) tests/*.c $(TSTS) -o $(TEST_DIR)/all_tests $(FLAGS)
	$(TEST_DIR)/all_tests

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	xdg-open out/index.html

valgrind_test: test
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes $(TEST_DIR)/all_tests > valgrind_summary.txt 2>&1 
	grep "ERROR SUMMARY:" valgrind_summary.txt


clean:
	rm -rf *.o *.exe tests/*.o *.a *.gc* all_tests out *.html *.info *.out *gcov valgrind_summary.txt $(TEST_DIR) $(BUILD_DIR)
