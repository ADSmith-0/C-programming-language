#include <limits.h>
#include <stdio.h>
int getMaxSizeUInt();
unsigned rightRotation(unsigned x, int rotation);

int uIntMaxSize;

int main() {
  uIntMaxSize = getMaxSizeUInt();
  int x = 48;
  int rotation = 2;
  printf("before: %d, rotation: %d, after: %u", x, rotation,
         rightRotation(x, rotation));

  return 0;
}

int getMaxSizeUInt() {
  int iterations = 0;
  for (int i = 1; i - 1 != UINT_MAX; i *= 2) {
    iterations++;
  }

  return iterations;
}

unsigned int rightRotation(unsigned x, int rotation) {
  return x >> rotation | x << (uIntMaxSize - rotation);
}
