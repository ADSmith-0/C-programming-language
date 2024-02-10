#include <stdio.h>
#define UPPER 300
#define LOWER 0

int main() {
  for (int fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit -= 20) {
    printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit + 32.0));
  }
}
