#include <stdio.h>
int main() {
  int lower = 0;
  int upper = 300;
  int step = 20;

  int celsius;
  int fahrenheit = lower;
  while (fahrenheit <= upper) {
    celsius = 5 * (fahrenheit - 32) / 9;
    printf("%d\t%d\n", fahrenheit, celsius);
    fahrenheit = fahrenheit + step;
  }
  return 0;
}
