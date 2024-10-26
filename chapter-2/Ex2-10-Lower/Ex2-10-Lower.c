
#include <stdio.h>
char toLower(char input);

int main() {
  char x = 'A';
  printf("before: %c, after: %c\n", x, toLower(x));
  return 0;
}

char toLower(char input) {
  return (input >= 'A' && input <= 'Z') ? input - ('A' - 'a') : input;
}
