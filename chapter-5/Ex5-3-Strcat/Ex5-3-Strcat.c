#include <stdio.h>
void mystrcat(char *s, char *t);

int main() {
  char str[12] = "hello";
  mystrcat(str, " world");
  printf("%s\n", str);
}

void mystrcat(char *s, char *t) {
  while (*s++)
    ;
  s--;

  while ((*s++ = *t++))
    ;
}
