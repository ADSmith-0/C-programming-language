#include <stdio.h>
#define MAX_LENGTH 1000
#define NUMBER_OF_COLUMNS 4

int getLine(char line[], int limit);
void clear(char line[], int limit);
int entab(char to[], char from[], int numberOfColumns);
int spacesToTabs(char line[], int spaces, int currentIndex,
                 int numberOfColumns);

int main() {
  int length = 0;
  int entabbedLength = 0;

  char line[MAX_LENGTH];
  char entabbedLine[MAX_LENGTH];

  while ((length = getLine(line, MAX_LENGTH)) > 0) {
    clear(entabbedLine, MAX_LENGTH);
    entabbedLength = entab(entabbedLine, line, NUMBER_OF_COLUMNS);
    printf("original length: %4d, original: %s\nentabbed length: %4d, "
           "entabbed: %s\n\n",
           length, line, entabbedLength, entabbedLine);
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

int entab(char to[], char from[], int numberOfColumns) {
  int toIndex = 0;
  int fromIndex = 0;
  int spaceCounter = 0;

  while (from[fromIndex] != '\0') {
    if (from[fromIndex] != ' ') {
      if (spaceCounter > 0) {
        toIndex = spacesToTabs(to, spaceCounter, toIndex, numberOfColumns);
        spaceCounter = 0;
      }

      to[toIndex] = from[fromIndex];
      toIndex++;
    } else {
      spaceCounter++;
    }

    fromIndex++;
  }

  if (spaceCounter > 0) {
    toIndex = spacesToTabs(to, spaceCounter, toIndex, numberOfColumns);
  }

  to[toIndex] = '\0';
  return toIndex;
}

int spacesToTabs(char line[], int spaces, int currentIndex,
                 int numberOfColumns) {
  int numberOfTabs = spaces / numberOfColumns;
  int numberOfSpaces = spaces % numberOfColumns;

  int i = 0;
  while (i < numberOfTabs) {
    line[currentIndex] = '\t';
    currentIndex++;
    i++;
  }

  i = 0;
  while (i < numberOfSpaces) {
    line[currentIndex] = ' ';
    currentIndex++;
    i++;
  }

  return currentIndex;
}
