#include <stdio.h>
int strLen(char *);

int main() {
  char *str = "Hello world!";
  printf("str: %s, length: %d\n", str, strLen(str));
  return 0;
}

int strLen(char *s) {
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;

  return n;
}
