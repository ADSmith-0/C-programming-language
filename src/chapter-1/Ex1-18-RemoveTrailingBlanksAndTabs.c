#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int getLine(char line[], int limit);
int trim(char to[], char from[], int limit);
bool isSpace(char character);

int main() {
  char line[MAX_LENGTH];
  int length = 0;

  char trimmedLine[MAX_LENGTH];

  while ((length = getLine(line, MAX_LENGTH)) > 0) {
    int trimmedLength = trim(trimmedLine, line, MAX_LENGTH);
    printf("Original Length: %d\nOriginal Line: %s\nTrimmed Length: "
           "%d\nTrimmed Line: %s\n\n",
           length, line, trimmedLength, trimmedLine);
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

int trim(char to[], char from[], int limit) {
  int strStart = 0;
  int strEnd = strlen(from) - 1;

  while (isSpace(from[strStart])) {
    ++strStart;
  }

  if (strStart == strlen(from) - 1) {
    return 0;
  }

  while (isSpace(from[strEnd])) {
    --strEnd;
  }

  for (int i = 0; i <= limit; i++) {
    to[i] = '\0';
  }

  int toLength = 0;
  for (int i = strStart; i <= strEnd; i++) {
    to[i - strStart] = from[i];
    ++toLength;
  }

  return toLength;
}

bool isSpace(char character) { return character == '\t' || character == ' '; }
