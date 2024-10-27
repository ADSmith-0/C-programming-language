#include <stdio.h>
#include <string.h>
void reverse(char[], char[]);

int main() {
  char from[] = "hello world";
  char to[20];

  reverse(to, from);
  printf("from:\t%s\nto:\t%s\n", from, to);

  return 0;
}

void reverse(char to[], char from[]) {
  int toLength = strlen(to);
  int fromLength = strlen(from);
  int currentFromIndex = (fromLength - 1) - toLength;

  to[toLength] = from[currentFromIndex];

  if (toLength != fromLength) {
    return reverse(to, from);
  }

  to[++toLength] = '\0';
}
