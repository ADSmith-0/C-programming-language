/*
 * Since the right most bit controls whether the number is odd or even, it will
 * always change when doing x - 1, and the & will get rid of it, this will
 * happen recursively up the chain for each 1
 */

#include <stdio.h>
int bitCount(unsigned int x);

int main() {
  int x = 6;
  printf("%u, number of 1's: %d\n", x, bitCount(x));
  return 0;
}

int bitCount(unsigned int x) {
  int i;
  for (i = 0; x != 0; x &= (x - 1)) {
    i++;
  }

  return i;
}
