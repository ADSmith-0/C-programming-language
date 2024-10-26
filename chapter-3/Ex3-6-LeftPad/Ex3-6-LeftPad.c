#include <limits.h>
#include <stdio.h>
#include <string.h>
void leftPad(int n, char output[], int minLength);
void reverse(char str[]);

int main() {
  int x = -200;
  char str[100];

  leftPad(x, str, 10);
  printf("number: %d, string: %s\n", x, str);

  return 0;
}

void leftPad(int n, char output[], int minLength) {
  int i = 0;
  char sign = 1;
  char isNegativeMax = 0;

  if (n < 0) {
    sign = -1;
    if (n == INT_MIN) {
      isNegativeMax = 1;
      n++;
    }
    n = -n;
  }

  do {
    output[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) {
    if (isNegativeMax) {
      output[0]++;
    }
    output[i++] = '-';
  }

  while (i < minLength) {
    output[i++] = ' ';
  }

  reverse(output);
  output[i] = '\0';
}

void reverse(char str[]) {
  int i, j, temp;
  int strLength = strlen(str);

  for (i = 0; i < strlen(str) / 2; i++) {
    j = strLength - (i + 1);
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}
