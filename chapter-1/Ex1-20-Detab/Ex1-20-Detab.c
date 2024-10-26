#include <stdio.h>
#define MAX_LENGTH 1000
#define COLUMN_SIZE 2

int getLine(char line[], int limit);
void clear(char line[], int limit);
int detab(char to[], char from[], int columnSize);

int main() {
  int length = 0;
  int detabbedLength = 0;

  char line[MAX_LENGTH];
  char detabbedLine[MAX_LENGTH];

  while ((length = getLine(line, MAX_LENGTH)) > 0) {
    clear(detabbedLine, MAX_LENGTH);
    detabbedLength = detab(detabbedLine, line, COLUMN_SIZE);
    printf("original length: %4d, original: %s\ndetabbed length: %4d, "
           "detabbed: %s\n\n",
           length, line, detabbedLength, detabbedLine);
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

int detab(char to[], char from[], int columnSize) {
  int toIndex = 0;
  int fromIndex = 0;

  while (from[fromIndex] != '\0') {
    if (from[fromIndex] == '\t') {
      for (int i = 0; i < columnSize - 1; i++) {
        to[toIndex++] = ' ';
      }
      to[toIndex] = ' ';
    } else {
      to[toIndex] = from[fromIndex];
    }

    toIndex++;
    fromIndex++;
  }

  return toIndex;
}
