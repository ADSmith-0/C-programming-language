#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <strings.h>
void intToBase(int n, char output[], int base);

int main() {
  int x = 910;
  char output[100];

  intToBase(x, output, 16);
  printf("input: %d\toutput: %s\n", x, output);

  return 0;
}

void intToBase(int n, char output[], int base) {
  int indices, x;
  int outputIndex = 0;
  char isNegativeMax = 0;

  if (n < 0) {
    output[outputIndex++] = '-';
    if (n == INT_MIN) {
      isNegativeMax = 1;
      n++;
    }
    n = -n;
  }

  for (indices = 0, x = 1; (x *= base) < n; indices++)
    ;

  int remainder = n;
  int result;
  for (int j = indices; j >= 0; j--) {
    result = floor(remainder / pow(base, j));
    remainder -= (result * pow(base, j));
    output[outputIndex++] =
        (result >= 0 && result <= 9) ? result + '0' : result + ('a' - 10);
  }

  if (isNegativeMax) {
    outputIndex--;
    output[outputIndex++] += 1;
  }

  output[outputIndex] = '\0';
}
