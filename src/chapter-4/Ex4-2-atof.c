#include <ctype.h>
#include <stdio.h>

double atof(char num[]);

int main() {
  char str[] = " -123.44e-5";

  printf("%s, %f\n", str, atof(str));

  return 0;
}

double atof(char num[]) {
  double val, power, exponent;
  int i;
  char sign, eSign;

  for (i = 0; isspace(num[i]); i++)
    ;

  sign = (num[i] == '-') ? -1 : 1;
  if (num[i] == '+' || num[i] == '-') {
    i++;
  }
  for (val = 0.0; isdigit(num[i]); i++) {
    val = 10.0 * val + (num[i] - '0');
  }
  if (num[i] == '.') {
    i++;
  }
  for (power = 1.0; isdigit(num[i]); i++) {
    val = 10.0 * val + (num[i] - '0');
    power *= 10.0;
  }
  if (num[i] == 'e') {
    i++;
  }

  eSign = (num[i] == '-') ? -1 : 1;
  if (num[i] == '-') {
    i++;
  }
  for (exponent = 0.0; isdigit(num[i]); i++) {
    exponent = 10.0 * exponent + (num[i] - '0');
  }

  double e = 1.0;
  for (int j = 0; j < exponent; j++) {
    e = (eSign < 0) ? e / 10.0 : e * 10.0;
  }

  return ((val / power) * sign) * e;
}
