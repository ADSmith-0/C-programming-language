#include <stdio.h>
unsigned getbits(unsigned uInt, int position, int numOfBits);

int main() {
  unsigned x = 5;
  printf("%u", getbits(x, 2, 2));
  return 0;
}

unsigned getbits(unsigned uInt, int position, int numOfBits) {
  return (uInt >> (position + 1 - numOfBits)) & ~(~0 << numOfBits);
}
