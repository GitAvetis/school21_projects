#include "s21_grep_io.h"

int main(int argc, char *argv[]) {
  options opt = {0};
  parse_options(argc, argv, &opt);
  to_grep(&opt);
  return 0;
};
