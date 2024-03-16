#include <stdio.h>

int power(int base, int n);

int power(int base, int n) {
  int result = 1;

  while (n > 0) {
    result *= base;
    --n;
  }

  return result;
}

int main() {
  printf("%d^%d: %d", 3, 2, power(3, 2));
  return 0;
}
