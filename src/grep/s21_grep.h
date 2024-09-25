#ifndef S21_GREP_H
#define S21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct options {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int bla;
} opts;

void parseOptions(int argc, char **argv, opts *options, regex_t *regex);
void readAndPrintFile(int argc, char **argv, opts *options, regex_t *regex);

#endif