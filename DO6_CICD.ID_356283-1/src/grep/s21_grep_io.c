#include "s21_grep_io.h"

void parse_options(int argc, char *argv[], options *opt) {
  opt->isValid = true;
  for (int i = 1; i < argc; i++) {
    if (opt->isValid) {
      if (argv[i][0] == '-') {
        if (argv[i][1] == 'e') {
          parse_e(opt, argv, &i, 2);
        } else if (argv[i][1] == 'f') {
          parse_f(opt, argv, &i, 2);
        } else {
          activated_options(argv, opt, &i);
        }
      } else if (!opt->e && !opt->f) {
        opt->e = true;
        opt->patterns[opt->patterns_count++] = argv[i];
      } else {
        opt->files[opt->files_count++] = argv[i];
      }
    } else {
      puts("invalid options1");
      opt->files_count = 0;
      break;
    }
  }
}

void activated_options(char *argv[], options *opt, int *i) {
  int length = strlen(argv[*i]);
  for (int j = 1; j < length; j++) {
    switch (argv[*i][j]) {
      case 'e':
        opt->e = true;  // шаблон
        parse_e(opt, argv, i, j + 1);
        j = length;
        break;
      case 'f':  // получает регулярные выражения из файлов
        opt->f = true;
        parse_f(opt, argv, i, j + 1);
        j = length;
        break;
      case 'i':  // игнор различий регистра
        opt->i = true;
        break;
      case 'v':
        opt->v = true;  // инверсия
        break;
      case 'c':
        opt->c = true;  // только кол-во совпадающих строк
        break;
      case 'l':  // только совпадающие файлы
        opt->l = true;
        break;
      case 'n':  // добовляет к строкам вывода номер строки из файла ввода
        opt->n = true;
        break;
      case 'h':  // выводит только строки без имён фйалов
        // printf("H");
        opt->h = true;
        break;
      case 's':  // не выводит сообщения об ошибках файлов
        opt->s = true;
        break;
      case 'o':  // выводит только совпадающую часть строки(!0)
        opt->o = true;
        break;

      default:
        opt->isValid = false;
        break;
    }
  }
  if (opt->o && (opt->l || opt->v || opt->c)) opt->o = false;
}
void to_grep(options *opt) {
  cook_pattern(opt);
  for (int i = 0; i < opt->files_count; i++) {
    opt->matches_count = 0;
    FILE *fp = fopen(opt->files[i], "r");
    if (fp) {
      char buf[BUF_SIZE];
      int n = 1;
      while (fgets(buf, BUF_SIZE, fp)) {
        int length = strlen(buf);
        if (buf[length - 1] != '\n') {
          buf[length + 1] = 0;
          buf[length] = '\n';
        }
        cook_main_data(opt, buf, opt->files[i], n);
        n++;
      }
      cook_aux_data(opt, opt->files[i]);
      fclose(fp);
    } else if (!opt->s)
      fprintf(stderr, "s21_grep: %s: No such file or directory\n",
              opt->files[i]);
  }
}
void cook_pattern_files(options *opt, int i) {
  char buf[BUF_SIZE];
  FILE *fp = fopen(opt->pattern_files[i], "r");
  if (fp) {
    while (fgets(buf, BUF_SIZE, fp)) {
      char *c = buf + strlen(buf) - 1;
      if (*c == '\n') *c = '\0';
      strcat(strcat(opt->pattern, !strlen(opt->pattern) ? "" : "|"),
             !strlen(buf) ? "." : buf);
    }
  } else
    printf("invalid options2\n");
}
void cook_pattern(options *opt) {
  for (int i = 0; opt->patterns[i]; i++) {
    strcat(strcat(opt->pattern, !strlen(opt->pattern) ? "" : "|"),
           !strlen(opt->patterns[i]) ? "." : opt->patterns[i]);
  }
  for (int j = 0; opt->pattern_files[j]; j++) cook_pattern_files(opt, j);
}
void parse_e(options *opt, char *argv[], int *i, int j) {
  opt->e = true;
  if (argv[*i][j] != '\0') {  // если патерн записан слитно с флагом;
    char buf[BUF_SIZE] = "";
    strcat(buf, argv[*i] + j);
    opt->patterns[(opt->patterns_count)++] = buf;
  } else {
    opt->patterns[(opt->patterns_count)++] = argv[++(*i)];
  }
}
void parse_f(options *opt, char *argv[], int *i, int j) {
  opt->f = true;
  if (argv[*i][j] != '\0') {
    char buf[BUF_SIZE] = "";
    strcat(buf, argv[*i] + j);
    opt->pattern_files[(opt->pattern_files_count)++] = buf;
  } else {
    opt->pattern_files[(opt->pattern_files_count)++] = argv[++(*i)];
  }
}
void cook_main_data(options *opt, char *line, char *file_name, int n) {
  regex_t regex;
  // printf("PATTERN: %s\n",opt->pattern);
  if (!regcomp(&regex, opt->pattern, opt->i ? REG_ICASE : REG_EXTENDED)) {
    if (regexec(&regex, line, 0, NULL, 0) == opt->v) {  // 0 в случае совпадения
      opt->matches_count++;
      if ((opt->c || opt->l) == 0) {
        if (opt->files_count > 1 && !opt->h) printf("%s:", file_name);
        if (opt->n) printf("%d:", n);
        if (!opt->o)
          fputs(line, stdout);
        else
          cook_with_o(regex, line, opt);
      }
    }
    regfree(&regex);
  }
}
void cook_aux_data(const options *opt, const char *file_name) {
  if (opt->c) {
    if (opt->l && !opt->h) {
      opt->files_count > 1 ? printf("%s:1\n", file_name) : printf("1\n");
    } else {
      if (opt->files_count > 1 && !opt->h) printf("%s:", file_name);
      printf("%d\n", opt->matches_count);
    }
  }
  if (opt->l && opt->matches_count) printf("%s\n", file_name);
}

void cook_with_o(regex_t regex, char *line, const options *opt) {
  while (!regexec(&regex, line, 0, NULL, 0)) {
    char buf[BUF_SIZE] = "";
    strcpy(buf, line);
    int left = 0;
    int right = strlen(buf);

    while (!regexec(&regex, buf + left, 0, NULL, 0))
      left++;  // проверка на совпадение строки с шаблоном
    left--;
    while (!regexec(&regex, buf + left, 0, NULL, 0)) {
      right--;
      buf[right] = 0;
    }
    // printf("r:%d\n",right);
    buf[right] = line[right];
    right++;
    // printf("r:%d\n",right);
    if (!opt->v) printf("%s\n", buf + left);
    int length = right - left + 1;
    for (int i = 0; i < length; i++) {
      line[left++] = line[right++];
    }
  }
  if (opt->v) printf("%s\n", line);
}
