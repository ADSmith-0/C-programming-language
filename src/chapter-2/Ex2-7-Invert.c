#include <stdio.h>
unsigned invert(unsigned uInt, int position, int numOfBits);

int main() {
  unsigned x = 39;
  printf("before: %u, after: %u\n", x, invert(x, 4, 2));
  return 0;
}

unsigned invert(unsigned uInt, int position, int numOfBits) {
  int endPosition = position + 1 - numOfBits;
  unsigned preBits = uInt >> (position + 1) << (position + 1);
  unsigned postBits = uInt & ~(~0 << endPosition);
  unsigned bitsToInvert = (uInt >> endPosition) & ~(~0 << numOfBits);
  unsigned invertedBits = (~bitsToInvert & ~(~0 << numOfBits)) << endPosition;
  return preBits | invertedBits | postBits;
}
