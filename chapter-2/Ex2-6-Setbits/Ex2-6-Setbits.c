#include <stdio.h>
unsigned setbits(unsigned uInt, int position, int numOfBits, unsigned newBits);

int main() {
  unsigned uInt = 51;
  unsigned bits = 3;
  printf("before: %u, bits: %u, after: %u", uInt, bits,
         setbits(uInt, 3, 2, bits));
  return 0;
}

unsigned setbits(unsigned uInt, int position, int numOfBits, unsigned newBits) {
  int endPosition = position + 1 - numOfBits;
  unsigned preBits = uInt >> (position + 1) << (position + 1);
  unsigned postBits = uInt & ~(~0 << endPosition);
  unsigned uIntMask = postBits | preBits;
  unsigned newBitsMask = newBits << endPosition;
  return uIntMask | newBitsMask;
}
