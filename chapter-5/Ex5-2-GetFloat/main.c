#include "GetFloat.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int getfloat(double *);

int main() {
  double p;
  getfloat(&p);
  printf("int: %g\n", p);
}

int getfloat(double *pn) {
  int c, sign;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    while (isspace(c = getch()))
      ;
  }
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }
  if (c == '.') {
    c = getch();
  }
  float i;
  for (i = 10; isdigit(c); c = getch(), i *= 10) {
    *pn += (c - '0') / i;
  }
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return c;
}
