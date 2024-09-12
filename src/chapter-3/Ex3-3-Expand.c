#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int getLine(char line[], int limit);
int isSymbol(char character);
void expand(char line[]);

int main() {
  char line[MAX_LENGTH];

  while (getLine(line, MAX_LENGTH) > 0) {
    expand(line);
  }

  return 0;
}

int getLine(char line[], int limit) {
  int i;
  char character;

  for (i = 0; i < limit - 1 && (character = getchar()) != '\n'; i++) {
    line[i] = character;
  }

  return i;
}

void expand(char line[]) {
  int i;
  char character;

  int lastIndex = strlen(line) - 1;

  for (i = 0; (character = line[i]) != '\0'; i++) {
    if (character != '-') {
      continue;
    }

    if (i == 0 || i == lastIndex) {
      putchar(character);
      continue;
    }

    char prevChar = line[i - 1];
    char nextChar = line[i + 1];

    for (int j = prevChar; j <= nextChar; j++) {
      putchar(j);
    }
  }

  printf("\n");
}
