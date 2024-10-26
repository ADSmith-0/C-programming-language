#include <stdio.h>
int main() {
  int arrLength = 10;
  int lengthCount[arrLength];
  int character;
  int length = 0;

  while ((character = getchar()) != EOF) {
    if (character == '\n' || character == '\t' || character == ' ') {
      ++lengthCount[length];
      length = 0;
    } else {
      ++length;
    }
  }

  // Horizontal
  // for (int i = 1; i <= 10; i++) {
  //   printf("%2d: ", i);
  //   for (int j = 0; j < lengthCount[i]; j++) {
  //     printf("=");
  //   }
  //   printf("\n");
  // }

  // Vertical
  for (int i = arrLength; i > 0; i--) {
    for (int j = 1; j <= arrLength; j++) {
      if (lengthCount[j] > i) {
        printf("|\t");
      } else {
        printf(" \t");
      }
    }
    printf("\n");
  }

  for (int i = 1; i <= arrLength; i++) {
    printf("%d\t", i);
  }
  printf("\n");
}
