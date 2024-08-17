#include <stdio.h>
#define MAX_LENGTH 1000

char getLine(char line[], int limit);
void clear(char line[], int limit);
int stripComments(char to[], char from[], int limit);
void append(char to[], char from[], int limit);

int main() {
  int length = 0;

  char line[MAX_LENGTH];
  char modifiedLine[MAX_LENGTH];
  char outputLine[MAX_LENGTH];

  while (getLine(line, MAX_LENGTH) != EOF) {
    clear(modifiedLine, MAX_LENGTH);
    if (stripComments(modifiedLine, line, MAX_LENGTH) > 0) {
      append(outputLine, modifiedLine, MAX_LENGTH);
    }
  }

  printf("%s", outputLine);

  return 0;
}

char getLine(char line[], int limit) {
  char character;
  int i = 0;

  while (i < limit - 1 && (character = getchar()) != '\n') {
    if (character == EOF) {
      return EOF;
    }
    line[i] = character;
    i++;
  }

  line[i++] = '\n';
  line[i] = '\0';
  return 0;
}

void clear(char line[], int limit) {
  int i = 0;

  while (i < limit - 1) {
    line[i] = '\0';
    i++;
  }
}

int stripComments(char to[], char from[], int limit) {
  int i = 0;
  int nonSpaceCharCount = 0;
  int slashCount = 0;
  char character;

  while (i < limit - 1 && ((character = from[i]) == '\t' || character == ' ' ||
                           character == '/')) {
    if (character == '/') {
      slashCount++;
      if (slashCount == 2) {
        return 0;
      }
    }
    i++;
  }

  i = 0;
  slashCount = 0;
  while (i < limit - 1 && (character = from[i]) != '\0') {
    if (character == '/') {
      slashCount++;
      if (slashCount == 2) {
        to[--i] = '\n';
        return i;
      }
    }
    to[i] = from[i];
    i++;
  }

  return i;
}

void append(char to[], char from[], int limit) {
  int toIndex = 0;
  int fromIndex = 0;

  while (toIndex < limit - 1 && to[toIndex] != '\0') {
    toIndex++;
  }

  while (toIndex < limit - 1 && from[fromIndex] != '\0') {
    to[toIndex] = from[fromIndex];
    toIndex++;
    fromIndex++;
  }
}
