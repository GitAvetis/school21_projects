#include <stdio.h>

#include "s21_files_io.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    single_print(stdin, NULL);
  } else {
    if (argv[1][0] == '-') {
      options opt = {0};
      parse_options(argc, argv, &opt);
      if (!opt.count)
        fprintf(stderr, "s21_cat: invalid option\n");
      else {
        print_file(argc, (const char **)argv, &opt);
      }
    } else {
      for (int i = 1; i < argc; i++)
        print_file(argc, (const char **)argv, NULL);
    }
  }

  return 0;
}
