#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int getLine(char line[], int limit);
void reverse(char to[], char from[]);

int main() {
  char line[MAX_LENGTH];
  char reversedLine[MAX_LENGTH];

  int length = 0;

  while ((length = getLine(line, MAX_LENGTH)) > 0) {
    reverse(reversedLine, line);
    printf("%s\n\n", reversedLine);
  }

  return 0;
}

int getLine(char line[], int limit) {
  char character;
  int i = 0;

  while (i < limit - 1 && (character = getchar()) != EOF && character != '\n') {
    line[i] = character;
    ++i;
  }

  line[i] = '\0';
  return i;
}

void reverse(char to[], char from[]) {
  int j = 0;

  for (int i = strlen(from) - 1; i >= 0; i--) {
    to[j] = from[i];
    j++;
  }
}
