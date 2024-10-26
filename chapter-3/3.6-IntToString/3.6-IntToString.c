#include <stdio.h>
#include <string.h>
void intToString(int n, char output[]);
void reverse(char str[]);

int main() {
  int x = -123;
  char output[100];

  intToString(x, output);
  printf("%s\n", output);

  return 0;
}

void intToString(int n, char output[]) {
  int i, sign;
  if ((sign = n) < 0) {
    n = -n;
  }
  i = 0;
  do {
    output[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) {
    output[i++] = '-';
  }
  output[i] = '\0';
  reverse(output);
}

void reverse(char str[]) {
  int i, j, temp;
  int strLength = strlen(str);

  for (i = 0; i < strLength / 2; i++) {
    j = strLength - (i + 1);
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}
