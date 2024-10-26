#include "calc.h"
#include <ctype.h>
#include <stdio.h>

static int bufchar = 0;

static int getch(void) {
  if (bufchar != 0) {
    int temp = bufchar;
    bufchar = 0;
    return temp;
  }
  return getchar();
}

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c != '.') {
    return c;
  }

  i = 0;
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';
  if (c != EOF) {
    bufchar = c;
  }

  return NUMBER;
}
