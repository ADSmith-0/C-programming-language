#include <stdio.h>
float fahrenheitToCelsius(float fahrenheit);

int main() {
  printf("F      C\n");
  for (int fahrenheit = 0; fahrenheit < 300; fahrenheit += 20) {
    printf("%3d: %6.1f\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
  }
}

float fahrenheitToCelsius(float fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit + 32.0);
}
