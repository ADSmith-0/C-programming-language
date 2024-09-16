/*
 * The current function for intToString in 3.6-IntToString makes the sign the
 * opposite before processing, for signed numbers the range is always -2^(dword
 * - 1) < n < 2^(dword - 1) - 1, so when we make the sign positive with the max
 * negative number we get an overflow, to fix this we simply ignore -1 if it's
 * at the max size then plus one back after
 */

#include <stdio.h>
#include <string.h>
void intToString(int n, char output[]);
void reverse(char str[]);
void clear(char str[]);

int main() {
  char output[100];

  int x = -1;

  while (x != 0) {
    intToString(x, output);
    printf("%12d\t%s\n", x, output);
    clear(output);
    x *= 2;
  }

  return 0;
}

void intToString(int n, char output[]) {
  int i = 0;
  char sign = 1;

  if (n < 0) {
    sign = -1;
    n++;
    n = -n;
  }

  do {
    output[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) {
    output[0]++;
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

void clear(char str[]) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = '\0';
  }
}
