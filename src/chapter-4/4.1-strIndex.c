#include <stdio.h>
#define NUM_OF_LINES 4
#define MAX_LENGTH 1000

int strIndex(char str[], char search[]);

int main() {
  char search[] = "ould";
  char line[MAX_LENGTH];
  char lines[NUM_OF_LINES][MAX_LENGTH] = {
      "Ah Love! could thou and I with Fate conspire",
      "To grasp this sorry Scheme of Things entire,",
      "Would not we shatter it to bits – and then",
      "Re-mould it nearer to the Heart’s Desire!"};

  for (int i = 0; i < NUM_OF_LINES; i++) {
    int result = strIndex(lines[i], search);
    if (result != -1) {
      printf("%s\n", lines[i]);
    }
  }
  printf("\n");

  return 0;
}

int strIndex(char str[], char search[]) {
  int i, j, k;

  for (i = 0; str[i] != '\0'; i++) {
    for (j = i, k = 0; search[k] != '\0' && str[j] == search[k]; j++, k++)
      ;

    if (k > 0 && search[k] == '\0') {
      return i;
    }
  }

  return -1;
}
