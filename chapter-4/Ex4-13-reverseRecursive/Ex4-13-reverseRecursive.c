#include <stdio.h>
void reverse(char[], int startIndex, int endIndex);

int main() {
  char s[] = "hello world";

  printf("original string: %s\n", s);
  reverse(s, 0, 10);
  printf("reversed string: %s\n", s);

  return 0;
}

void reverse(char s[], int startIndex, int endIndex) {
  int temp;

  temp = s[endIndex];
  s[endIndex] = s[startIndex];
  s[startIndex] = temp;

  if (startIndex < endIndex) {
    reverse(s, startIndex + 1, endIndex - 1);
  }
}
