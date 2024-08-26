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
  int s1Index = 0;
  int s2Index = 0;

  while (s1[s1Index] != '\0') {
    s2Index = 0;

    while (s2[s2Index] != '\0') {
      if (s2[s2Index] == s1[s1Index]) {
        return s1Index;
      }
      s2Index++;
    }

    s1Index++;
  }

  return -1;
}
