#include <stdio.h>

int hexToInt(char hex);

int main() {
  int value;
  char character;

  while ((character = getchar()) != EOF) {
    if (character == '\n') {
      continue;
    }

    value = hexToInt(character);
    printf("hex: %c, int: %d\n", character, value);
  }

  return 0;
}

int hexToInt(char hex) {
  int value = hex >= 'a' ? hex - ('a' - 'A') : hex;
  value -= '0';

  if (value >= 10) {
    value -= ('A' - '0');
    value += 10;
  }

  if (value >= 0 && value <= 15) {
    return value;
  }

  return -1;
}
