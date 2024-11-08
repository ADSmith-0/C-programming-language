#include "GetInt.h"
#include <ctype.h>
#include <stdio.h>

int getint(int *);

int main() {
  int p;
  getint(&p);
  printf("int: %d\n", p);
}

int getint(int *pn) {
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
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return c;
}
