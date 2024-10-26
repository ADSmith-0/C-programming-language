#include <stdio.h>
int main() {
  int letters[26];
  int character;

  while ((character = getchar()) != EOF) {
    if (character != ' ' && character != '\n' && character != '\t') {
      if (character >= 65 && character <= 90) {
        ++letters[character + 32 - 'a'];
      }
      if (character >= 97) {
        ++letters[character - 'a'];
      }
    }
  }

  for (int i = 10; i > 0; i--) {
    for (int j = 0; j < 26; j++) {
      if (letters[j] >= i) {
        printf("| ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  for (int i = 0; i < 26; i++) {
    printf("%c ", i + 'a');
  }
}
