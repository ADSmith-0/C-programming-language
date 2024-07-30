#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int getLine(char line[], int limit);
void copy(char to[], char from[]);
bool isSpace(char character);

int main() {
  char line[MAX_LENGTH];
  int length = 0;

  char trimmedLine[MAX_LENGTH];

  while ((length = getLine(line, MAX_LENGTH)) > 0) {
    copy(trimmedLine, line);
    printf("Original Length: %d\nOriginal Line: %s\nTrimmed Length: "
           "%lu\nTrimmed Line: %s\n",
           length, line, strlen(trimmedLine) - 1, trimmedLine);
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

  if (character == '\n') {
    line[i] = character;
    ++i;
  }

  line[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int strStart = 0;
  int strEnd = strlen(from) - 1;

  while (isSpace(from[strStart])) {
    ++strStart;
  }

  if (strStart == strlen(from) - 1) {
    to[0] = '\0';
    return;
  }

  while (isSpace(from[strEnd])) {
    --strEnd;
  }

  int toLength = 0;
  for (int i = strStart; i < strEnd; i++) {
    to[i - strStart] = from[i];
    ++toLength;
  }

  to[toLength] = '\n';
}

bool isSpace(char character) { return character == '\t' || character == ' '; }
