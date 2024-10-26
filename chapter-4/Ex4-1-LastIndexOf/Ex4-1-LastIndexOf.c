#include <stdio.h>
#include <string.h>
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
  int lineLength = strlen(line) - 1;
  int searchTermLength = strlen(searchTerm) - 1;

  for (i = lineLength; i >= 0; i--) {
    for (j = i, k = searchTermLength; line[j] == searchTerm[k] && k > 0;
         j--, k--)
      ;

    if (k == 0) {
      return i - searchTermLength;
    }
  }

  return -1;
}
