#include <stdio.h>
char strend(char *s, char *t);

int main() {
  char *s = "Hello world";
  char *t = "world";

  char contains = strend(s, t);

  printf("%d\n", contains);
}

char strend(char *s, char *t) {
  char *x = t;
  while (*s++)
    ;
  while (*t++)
    ;

  while (*--s == *--t) {
    if (x == t) {
      return 1;
    }
  }
  return 0;
}
