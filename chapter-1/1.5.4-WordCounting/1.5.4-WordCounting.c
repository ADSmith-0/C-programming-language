// 1.5.4
#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  int character;
  int lineCount = 0;
  int characterCount = 0;
  int wordCount = 0;
  int state = OUT;

  while ((character = getchar()) != EOF) {
    ++characterCount;
    if (character == '\n') {
      ++lineCount;
    }
    if (character == ' ' || character == '\n' || character == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++wordCount;
    }
  }

  printf("lines: %d, words: %d, characters: %d", lineCount, wordCount,
         characterCount);
}
