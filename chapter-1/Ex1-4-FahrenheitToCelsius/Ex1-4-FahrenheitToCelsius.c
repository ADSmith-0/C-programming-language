#include <stdio.h>
int main() {
  int lower = 0;
  int upper = 300;
  int step = 20;

  float celsius;
  float fahrenheit = lower;
  printf("Fahrenheit Celsius\n");
  while (fahrenheit <= upper) {
    celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
    printf("%10.0f %7.1f\n", fahrenheit, celsius);
    fahrenheit = fahrenheit + step;
  }
  printf("\n");
  printf("Celsius Fahrenheit\n");
  celsius = 0;
  while (celsius <= upper) {
    fahrenheit = (9.0 / 5.0) * (celsius + 32.0);
    printf("%7.0f %10.1f\n", celsius, fahrenheit);
    celsius = celsius + step;
  }
  return 0;
}
