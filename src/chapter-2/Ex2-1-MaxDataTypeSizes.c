#include <limits.h>
#include <stdio.h>

void usingLimits();
void usingComputation();

int main() {
  printf("Data Type\t%*c", 9, ' ');
  printf("Min\t%*c", 17, ' ');
  printf("Max\n");
  printf("Char\t%20d\t%20d\n", CHAR_MIN, CHAR_MAX);
  printf("UChar\t%20u\t%20u\n", 0, UCHAR_MAX);
  printf("Short\t%20d\t%20d\n", SHRT_MIN, SHRT_MAX);
  printf("UShort\t%20u\t%20u\n", 0, USHRT_MAX);
  printf("Int\t%20d\t%20d\n", INT_MIN, INT_MAX);
  printf("UInt\t%20u\t%20u\n", 0, UINT_MAX);
  printf("Long\t%20ld\t%20ld\n", LONG_MIN, LONG_MAX);
  printf("ULong\t%20d\t%20lu\n", 0, ULONG_MAX);

  return 0;
}

void usingLimits() {}
