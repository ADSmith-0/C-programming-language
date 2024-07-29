#include <stdio.h>
#define MAX_LENGTH 1000

int getLineLength(char line[], int limit);

int main() {
  char line[MAX_LENGTH];
  int length = 0;

  while ((length = getLineLength(line, MAX_LENGTH)) > 0) {
    if (length > 80) {
      printf("Length: %d\nLine: %s", length, line);
    }
  }

  return 0;
}

int getLineLength(char line[], int limit) {
  int i = 0;
  char character;

  while (i < limit - 1 && (character = getchar()) != EOF && character != '\n') {
    line[i] = character;
    ++i;
  }

  if (character == '\n') {
    line[i] = character;
    ++i;
  }

  line[i] = '\0';
  return i;
}
