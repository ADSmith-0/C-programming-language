#include <stdio.h>
#define MAX_LENGTH 20
int any(char s1[], char s2[]);

int main() {
  char input[MAX_LENGTH] = "hello world";
  char search[MAX_LENGTH] = "ld";

  printf("string: %s, search string: %s, index: %d", input, search,
         any(input, search));

  return 0;
}

int any(char s1[], char s2[]) {
  for (int s1Index = 0; s1[s1Index] != '\0'; s1Index++) {
    for (int s2Index = 0; s2[s2Index] != '\0'; s2Index++) {
      if (s2[s2Index] == s1[s1Index]) {
        return s1Index;
      }
    }
  }

  return -1;
}
