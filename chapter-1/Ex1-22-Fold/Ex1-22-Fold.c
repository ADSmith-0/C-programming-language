#include <stdio.h>
#define MAX_LENGTH 1000
#define WRAP_LENGTH 20

int getLine(char line[], int limit);
void clear(char line[], int limit);
void wrap(char output[], char input[], int wrapLength);

int main() {
  int length = 0;

  char line[MAX_LENGTH];
  char wrappedLine[MAX_LENGTH];

  while ((length = getLine(line, MAX_LENGTH)) > 0) {
    clear(wrappedLine, MAX_LENGTH);
    wrap(wrappedLine, line, WRAP_LENGTH);
    printf("%s\n\n", wrappedLine);
  }

  return 0;
}

int getLine(char line[], int limit) {
  char character;
  int i = 0;

  while (i < limit - 1 && (character = getchar()) != EOF && character != '\n') {
    line[i] = character;
    i++;
  }

  line[i] = '\0';
  return i;
}

void clear(char line[], int limit) {
  int i = 0;

  while (i < limit - 1) {
    line[i] = '\0';
    i++;
  }
}

void wrap(char output[], char input[], int wrapLength) {
  int outputIndex = 0;
  int inputIndex = 0;

  int previousWrapIndex = 0;
  int wrapIndex = 0;

  while (input[inputIndex] != '\0') {
    if (input[inputIndex] == ' ') {
      wrapIndex = outputIndex;
    }

    if (outputIndex > previousWrapIndex + wrapLength && wrapIndex > 0) {
      output[wrapIndex] = '\n';
      previousWrapIndex = wrapIndex;
    } else if (wrapIndex == 0 && outputIndex % wrapLength == 0) {
      output[outputIndex] = '\n';
      outputIndex++;
    }

    output[outputIndex] = input[inputIndex];
    inputIndex++;
    outputIndex++;
  }
}
