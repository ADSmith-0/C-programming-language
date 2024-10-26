#include <stdio.h>
#define MAX_LENGTH 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  char line[MAX_LENGTH];
  char longest[MAX_LENGTH];

  int max = 0;
  int length;

  while ((length = getLine(line, MAX_LENGTH)) > 0) {
    if (length > max) {
      max = length;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

int getLine(char line[], int lim) {
  int character;
  int i = 0;

  while (i < lim - 1 && (character = getchar()) != EOF && character != '\n') {
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

void copy(char to[], char from[]) {
  int i = 0;

  while (from[i] != '\0') {
    to[i] = from[i];
    ++i;
  }
}
