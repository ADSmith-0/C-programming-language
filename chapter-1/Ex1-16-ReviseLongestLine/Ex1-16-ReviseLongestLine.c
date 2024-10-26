#include <stdio.h>
#define MAX_LENGTH 5

int getLine(char line[], int limit);
void copy(char to[], char from[]);

int main() {
  char line[MAX_LENGTH];
  int length = 0;

  char longestLine[MAX_LENGTH];
  int longestLength = 0;

  while ((length = getLine(line, MAX_LENGTH)) > 0) {
    if (length > longestLength) {
      longestLength = length;
      copy(longestLine, line);
    }
  }

  if (longestLength > 0) {
    printf("Length: %d\nLine: %s", longestLength, longestLine);
  }

  return 0;
}

int getLine(char line[], int limit) {
  int i = 0;
  char character;

  while (i < limit - 1 && (character = getchar()) != EOF && character != '\n') {
    line[i] = character;
    ++i;
  }

  if (character == '\n') {
    line[i] = '\n';
    ++i;
  }

  line[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;

  while (from[i] != '\0') {
    to[i] = from[i];
    ++i;
  }
}
