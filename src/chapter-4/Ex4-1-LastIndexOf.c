#include <stdio.h>
#define MAX_LENGTH 1000

int lastStrIndex(char line[], char searchTerm[]);

int main() {
  char searchTerm[] = "ea";
  char line[MAX_LENGTH] = "Re-mould it nearer to the Heart’s Desire!";

  printf("last index: %d\n", lastStrIndex(line, searchTerm));

  return 0;
}

int lastStrIndex(char line[], char searchTerm[]) {
  int i, j, k;
  int lastIndexOf = -1;

  for (i = 0; line[i] != '\0'; i++) {
    for (j = i, k = 0; line[j] == searchTerm[k] && searchTerm[k] != '\0';
         j++, k++)
      ;

    if (k > 0 && searchTerm[k] == '\0') {
      lastIndexOf = i;
    }
  }

  return lastIndexOf;
}
