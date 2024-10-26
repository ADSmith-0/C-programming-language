// 1.5.3
// Exercise 1-8
#include <stdio.h>
int main() {
  int c, count;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      ++count;
    }
  }

  printf("%d\n", count);
}
