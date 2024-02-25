// Ex 1-12
#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  int character;
  int status = OUT;

  while ((character = getchar()) != EOF) {
    if (character == '\t' || character == ' ') {
      putchar('\n');
    } else {
      putchar(character);
    }
  }
}
