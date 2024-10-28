#include <stdio.h>
#define for(A) for (int Z = 0; Z < A; Z++)
#define max(A, B) ((A) > (B) ? (A) : (B))

// #undef - Used to undefine a macro

#define print(expr, type) printf(#expr " = " type "\n", expr)

int main() {
  int i = 1;

  for (10) {
    i *= 2;
    print(max(i, 200), "%d");
  }

  return 0;
}
