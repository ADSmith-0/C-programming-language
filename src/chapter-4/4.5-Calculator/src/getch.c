#include <stdio.h>
#define BUFSIZE 100
static char buf[BUFSIZE];
static int bufp = 0;

// comment!
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
    return;
  }
  buf[bufp++] = c;
}
