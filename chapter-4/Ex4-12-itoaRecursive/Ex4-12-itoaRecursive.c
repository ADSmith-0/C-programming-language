#include <stdio.h>
#include <string.h>
void itoa(int, char[]);

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
    out[0] = '-';
  }

  if (n / 10) {
    itoa((n / 10), out);
  }

  out[strlen(out)] = n % 10 + '0';
}
