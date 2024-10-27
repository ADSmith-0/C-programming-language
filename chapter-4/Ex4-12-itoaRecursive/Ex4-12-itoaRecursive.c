#include <stdio.h>
#include <string.h>
void itoa(int, char[]);
void reverse(char[]);

int main() {
  int n = 123;
  char str[100];

  printf("before: %d\n", n);
  itoa(n, str);
  printf("after: %s\n", str);
  return 0;
}

void itoa(int n, char out[]) {
  if (n < 0) {
    n = -n;
  }

  int i;
  for (i = 0; out[i] != '\0'; i++)
    ;

  out[i++] = n % 10 + '0';
  out[i] = '\0';

  if ((n / 10) > 0) {
    return itoa((n / 10), out);
  }

  reverse(out);
}

void reverse(char s[]) {
  int i, j, temp;
  int length = strlen(s);

  for (i = 0; i < length / 2; i++) {
    j = length - (i + 1);
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
