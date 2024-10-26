#include <stdio.h>
#define MAX_LENGTH 1000

void expressionVersion(char line[], int limit);
void loopVersion(char line[], int limit);

int main() {
  char line[MAX_LENGTH];

  // expressionVersion(line, MAX_LENGTH);
  loopVersion(line, MAX_LENGTH);

  return 0;
}

void expressionVersion(char line[], int limit) {
  int i = 0;
  char character;

  while (i < limit - 1 && (character = getchar()) && character != EOF) {
    putchar(character);
    i++;
  }
}

void loopVersion(char line[], int limit) {
  int i = 0;
  char character;

  while (i < limit - 1) {
    character = getchar();
    if (character != EOF) {
      putchar(character);
    }
    i++;
  }
}
