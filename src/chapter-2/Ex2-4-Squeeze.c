#include <stdio.h>
#define MAX_LENGTH 20
enum bool { FALSE, TRUE };

void squeeze(char s1[], char s2[]);

int main() {
  char line[MAX_LENGTH] = "hello world";
  printf("original: %s, ", line);
  squeeze(line, "hello ");
  printf("squeezed: %s\n", line);
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int s1WriteIndex = 0;
  enum bool match;

  for (int s1ReadIndex = 0; s1[s1ReadIndex] != '\0'; s1ReadIndex++) {
    match = FALSE;

    for (int s2Index = 0; s2[s2Index] != '\0'; s2Index++) {
      if (s2[s2Index] == s1[s1ReadIndex]) {
        match = TRUE;
        break;
      }
    }

    if (!match) {
      s1[s1WriteIndex++] = s1[s1ReadIndex];
    }
  }

  s1[s1WriteIndex] = '\0';
}
