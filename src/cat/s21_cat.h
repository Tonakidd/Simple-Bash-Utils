#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FOPEN_read "r"

typedef struct options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} opts;

void parseOptions(int argc, char **argv, opts *options);
void readAndPrintFile(int argc, char **argv, opts *options);

#endif