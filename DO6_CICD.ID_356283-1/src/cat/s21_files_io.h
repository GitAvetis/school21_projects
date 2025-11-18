#ifndef FILES_IO
#define FILES_IO
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct options {
  bool b;
  bool e;
  bool n;
  bool s;
  bool t;
  bool v;
  int count;
  int empty_lines;

} options;

void print_file(int argc, const char *argv[], options *opt);
void single_print(FILE *fp, options *opt);
void parse_options(int argc, char *argv[], options *opt);
void parse_long_options(const char *argv, options *opt);
void activated_options(const char *arg, options *opt);
void cook_non_printed(int *c, const options *opt);
void cat_cook(int *c, const int *prev, options *opt, FILE *fp);
void cook_empty(const int *c, const int *prev, options *opt);
void cook_sqzd(int *c, FILE *fp, options *opt);
void cook_n(int prev, options *opt);

#endif
