#include <stdio.h>
#define swap(t, x, y)                                                          \
  {                                                                            \
    t temp;                                                                    \
    temp = x;                                                                  \
    x = y;                                                                     \
    y = temp;                                                                  \
  }
#define var(x1, x2) x1##x2

int main() {
  int x = 1;
  int y = 2;
  int x1 = 5;

  printf("x: %d, y: %d\n", x, y);
  swap(int, x, y);
  printf("x: %d, y: %d\n", x, y);
  swap(int, x, y);
  printf("x: %d, y: %d\n", x, y);
  printf("x1: %d\n", var(x, 1));
}
