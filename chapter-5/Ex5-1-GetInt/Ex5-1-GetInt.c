#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
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

#define MAX_SIZE 100
int buffer[MAX_SIZE];
int bufpos = 0;

int getch() { return bufpos > 0 ? buffer[--bufpos] : getchar(); }

void ungetch(int c) {
  if (bufpos > MAX_SIZE) {
    printf("error: not enough space to add another character");
    return;
  }
  buffer[bufpos++] = c;
}
