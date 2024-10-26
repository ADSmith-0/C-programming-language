#include <stdio.h>
#define MAXVAL 100
#include "calc.h"

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp >= MAXVAL) {
    printf("error: stack full, can't push %g\n", f);
    return;
  }
  val[sp++] = f;
}

double pop(void) {
  if (sp <= 0) {
    printf("error: stack empty\n");
    return 0.0;
  }
  return val[--sp];
}
