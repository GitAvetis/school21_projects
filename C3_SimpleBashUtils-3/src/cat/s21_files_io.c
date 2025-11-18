#include "s21_files_io.h"

void print_file(int argc, const char *argv[], options *opt) {
  int i = opt ? 1 + opt->count : 1;
  for (; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp != NULL) {
      single_print(fp, opt);
      fclose(fp);
    } else {
      fprintf(stderr, "s21_cat: %s: No such file or directory\n", argv[i]);
    }
  }
}
void parse_options(int argc, char *argv[], options *opt) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      opt->count++;
      if (!strstr(argv[i] + 1, "-"))
        activated_options(argv[i], opt);
      else if (argv[i][1] == '-')
        parse_long_options(argv[i], opt);
    }
    if (!opt->count) break;
  }
}
void parse_long_options(const char *argv, options *opt) {
  if (!strcmp(argv + 2, "number-nonblank"))
    opt->b = true;
  else if (!strcmp(argv + 2, "number"))
    opt->n = true;
  else if (!strcmp(argv + 2, "squeeze-blank"))
    opt->s = true;
  else
    opt->count = 0;
}

void activated_options(const char *arg, options *opt) {
  int length = strlen(arg);

  for (int i = 1; i < length; i++) {
    if (opt->count) {
      switch (arg[i]) {
        case 'b':  // нумеруетпустые строки
          opt->b = true;
          break;
        case 'E':
          opt->e = true;
          break;
        case 'e':  // в конец строки $ и -v
          opt->e = true;
          opt->v = true;
          break;
        case 'n':  // нумерует выходные строки
          opt->n = true;
          break;
        case 's':  // сжимает нескольско смежных пустых строк
          opt->s = true;
          break;
        case 'T':
          opt->t = true;
          break;
        case 't':  // табы в виде ^| и v
          opt->v = true;
          opt->t = true;
          break;
        case 'v':  //  отоброжение невидимых символов
          opt->v = true;
          break;

        default:
          opt->count = 0;
          break;
      }
    } else
      break;
  }
}

void cook_non_printed(int *c, const options *opt) {
  if (*c == '\n') {
    if (opt->e) printf("$");
  } else if (*c == '\t') {
    if (opt->t) {
      printf("^");
      *c = 'I';
    }
  } else if (opt->v) {
    if (*c <= 31) {
      printf("^");
      *c += 64;
    } else if (*c == 127) {
      printf("^");
      *c = '?';
    } else if (*c >= 128 && *c < 128 + 32) {
      printf("M-^");
      *c -= 64;
    }
  }
}

void single_print(FILE *fp, options *opt) {
  int c;
  int prev = '\n';
  if (opt) {
    opt->empty_lines = 0;
    opt->count = 1;
  }
  while ((c = fgetc(fp)) != EOF) {
    if (opt) cat_cook(&c, &prev, opt, fp);
    if (c != EOF) fputc(c, stdout);

    prev = c;
  }
}
void cat_cook(int *c, const int *prev, options *opt, FILE *fp) {
  cook_empty(c, prev, opt);
  cook_sqzd(c, fp, opt);
  if (*c != EOF) {
    cook_n(*prev, opt);
    cook_non_printed(c, opt);
  }
}

void cook_empty(const int *c, const int *prev, options *opt) {
  if (*prev == '\n' && *c == '\n')
    opt->empty_lines++;
  else
    opt->empty_lines = 0;
}
void cook_sqzd(int *c, FILE *fp, options *opt) {
  if (opt->s && opt->empty_lines > 1) {
    while (*c == '\n') *c = fgetc(fp);
    opt->empty_lines = 0;
  }
}
void cook_n(int prev, options *opt) {
  if (prev == '\n' && (opt->n || opt->b)) {
    if (!(opt->b && opt->empty_lines > 0)) {
      printf("%6d\t", opt->count);
      opt->count++;
    }
  }
}
