#include "s21_cat.h"

int main(int argc, char **argv) {
  char s[4096];
  opts options = {0};

  parseOptions(argc, argv, &options);

  if (!argv[optind]) {
    int lin = 0;
    while (1) {
      scanf("%s", s);
      if (options.b) {
        printf("%6d\t", ++lin);
      }
      printf("%s\n", s);
    }
  }
  readAndPrintFile(argc, argv, &options);
  return 0;
}

void readAndPrintFile(int argc, char **argv, opts *options) {
  char ch;
  char endOfLine = '$';
  FILE *file;
  int gobble = 0;
  int line = 0;
  int prev;

  while (argc > 0 && argv[optind]) {
    file = fopen(argv[optind], FOPEN_read);
    if (file) {
      for (prev = '\n'; (ch = fgetc(file)) != EOF; prev = ch) {
        switch (prev) {
          case '\n':  //проверка ПРЕДЫДУЩЕГО СИМВОЛА
            if (options->s) {  //СЪЕДАЕТ пустые строки //DONE
              if (ch == '\n') {
                if (gobble) {
                  continue;
                } else {
                  gobble = 1;
                }
              } else {
                gobble = 0;
              }
            }
            if (options->b) {  //нумерует НЕПУСТЫЕ строки //DONE
              if (ch == '\n') {
                printf("%c", ch);
              } else {
                printf("%d\t", ++line);
              }
            }
            if (!options->b && options->n) {  //нумерует ВСЕ строки //DONE
              printf("%6d\t", ++line);
            }
            break;
        }
        switch (ch) {  //проверка НЫНЕШНЕГО СИМВОЛА
          case '\n':
            if (options->e) {  //ставит символ ДОЛЛАРА //DONE
              printf("%c", endOfLine);
            }
            break;
          case '\t':
            if (options->t) {
              printf("^I");
              continue;
            }
            break;
          case 127:
            if (options->v) {
              ch = '?';
              printf("^");
            }
            break;
          default:
            if (options->v) {
              if (ch < 32 && ch != 9 && ch != 10) {
                ch = ch + 64;
                printf("^");
              }
            }
            break;
        }
        printf("%c", ch);
      }
    }
    optind++;
  }
  if (!file) {
    fprintf(stderr, "No such file: %s\n", argv[optind]);
    exit(EXIT_FAILURE);
  }
  fclose(file);
}

void parseOptions(int argc, char **argv, opts *options) {
  int opt;
  int option_index = 0;

  static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                         {"number", 0, 0, 'n'},
                                         {"squeeze-blank", 0, 0, 's'},
                                         {0, 0, 0, 0}};
  while ((opt = getopt_long(argc, argv, "+benstvTE", long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'b':
        options->b = 1;
        break;
      case 'E':
        options->e = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'T':
        options->t = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      default:
        fprintf(stderr, "Use: %s [OPTION] [FILE]...\n", argv[0]);
        exit(1);
    }
  }
}