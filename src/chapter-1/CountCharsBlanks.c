// Ex 1-9
#include <stdio.h>
int main() {
  int c, prevC;

  while ((c = getchar()) != EOF) {
    if (prevC == ' ' && c == ' ') {
      continue;
    }
    putchar(c);
    prevC = c;
  }
}
