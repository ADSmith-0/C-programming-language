#include <stdio.h>

#define MAXLINE 1000

int maxLength;
char line[MAXLINE];
char longestLine[MAXLINE];

int getLine(void);
void copy(void);

int main() {
  int length = 0;
  extern int maxLength;
  extern char longestLine[];

  while ((length = getLine()) > 0) {
    if (length > maxLength) {
      maxLength = length;
      copy();
    }
  }

  if (maxLength > 0) {
    printf("%s", longestLine);
  }

  return 0;
}

int getLine() {
  int character;
  int i = 0;
  extern char line[];

  while (i < MAXLINE - 1 && (character = getchar()) != EOF &&
         character != '\n') {
    line[i] = character;
    i++;
  }

  line[i] = '\0';
  return i;
}

void copy() {
  int i = 0;
  extern char line[], longestLine[];

  while ((longestLine[i] = line[i]) != '\0') {
    i++;
  }
}
