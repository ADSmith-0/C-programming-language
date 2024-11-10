#include <stdio.h>

#define MAX_SIZE 100
int static buffer[MAX_SIZE];
int static bufpos = 0;

int getch() { return bufpos > 0 ? buffer[--bufpos] : getchar(); }

void ungetch(int c) {
  if (bufpos > MAX_SIZE) {
    printf("error: not enough space to add another character");
    return;
  }
  buffer[bufpos++] = c;
}
