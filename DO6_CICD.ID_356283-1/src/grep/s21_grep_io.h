#ifndef FILES_IO
#define FILES_IO
#define SIZE 16
#define BUF_SIZE 4096
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct options {
  bool isValid;
  char *patterns[SIZE];
  char *pattern_files[SIZE];
  char pattern[BUF_SIZE];
  char *files[SIZE];
  bool e, v, i, l, c, n, h, s, f, o;
  int matches_count;
  int files_count;
  int patterns_count;
  int pattern_files_count;

} options;

// void print_debug(options opt);
// void print_arr(char *list[]);
void to_grep(options *opt);
void cook_pattern(options *opt);
void cook_pattern_files(options *opt, int i);
void cook_main_data(options *opt, char *line, char *file_name, int n);
void cook_aux_data(const options *opt, const char *filename);
void cook_with_o(regex_t regex, char *line, const options *opt);
void parse_options(int argc, char *argv[], options *opt);
void activated_options(char *arg[], options *opt, int *i);
void parse_e(options *opt, char *argv[], int *i, int j);
void parse_f(options *opt, char *argv[], int *i, int j);

#endif
