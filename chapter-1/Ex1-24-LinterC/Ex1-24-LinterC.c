#include <stdio.h>
#define MAX_LENGTH 1000

int main() {
  char line[MAX_LENGTH];
  char character;
  int i, braceCount, bracketCount, quoteCount, apostropheCount;
  i = braceCount = bracketCount = quoteCount = apostropheCount = 0;

  while (i < MAX_LENGTH - 1 && (character = getchar()) != EOF) {
    switch (character) {
    case '{': {
      braceCount++;
      break;
    }
    case '}': {
      braceCount--;
      break;
    }
    case '(': {
      bracketCount++;
      break;
    }
    case ')': {
      bracketCount--;
      break;
    }
    case '\'': {
      if (apostropheCount == 0) {
        apostropheCount++;
      } else if (apostropheCount == 1) {
        apostropheCount--;
      }
      break;
    }
    case '\"': {
      if (quoteCount == 0) {
        quoteCount++;
      } else if (quoteCount == 1) {
        quoteCount--;
      }
      break;
    }
    }

    if (braceCount == -1) {
      braceCount *= -1;
    }

    if (bracketCount == -1) {
      bracketCount *= -1;
    }

    i++;
  }

  if (braceCount != 0) {
    printf("- Incorrect number of braces\n");
  }

  if (bracketCount != 0) {
    printf("- Incorrect number of brackets\n");
  }

  if (quoteCount != 0) {
    printf("- Incorrect number of quotes\n");
  }

  if (apostropheCount != 0) {
    printf("- Incorrect number of apostrophes\n");
  }

  return 0;
}
