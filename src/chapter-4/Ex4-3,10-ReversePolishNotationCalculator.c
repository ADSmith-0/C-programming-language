#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OP 100
#define NUMBER '0'
#define LIB_FN 'a'

int getop(char[]);
void push(double);
double peek(void);
void duplicate(void);
void swap(void);
void clear(void);
double pop(void);

int main() {
  int type;
  double op2;
  char s[MAX_OP];
  char entered = 0;

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case LIB_FN:
      if (!strncmp(s, "pow", 3)) {
        double op2 = pop();
        push(pow(pop(), op2));
      } else if (!strncmp(s, "exp", 3))
        push(exp(pop()));
      else if (!strncmp(s, "log", 3))
        push(log(pop()));
      else if (!strncmp(s, "log10", 5))
        push(log10(pop()));
      else if (!strncmp(s, "sqrt", 4))
        push(sqrt(pop()));
      else if (!strncmp(s, "fabs", 4))
        push(fabs(pop()));
      else if (!strncmp(s, "ceil", 4))
        push(ceil(pop()));
      else if (!strncmp(s, "floor", 5))
        push(floor(pop()));
      else if (!strncmp(s, "sin", 3))
        push(sin(pop()));
      else if (!strncmp(s, "cos", 3))
        push(cos(pop()));
      else if (!strncmp(s, "tan", 3))
        push(tan(pop()));
      else if (!strncmp(s, "asin", 4))
        push(asin(pop()));
      else if (!strncmp(s, "acos", 4))
        push(acos(pop()));
      else if (!strncmp(s, "atan", 4))
        push(atan(pop()));
      else if (!strncmp(s, "sinh", 4))
        push(sinh(pop()));
      else if (!strncmp(s, "cosh", 4))
        push(cosh(pop()));
      else if (!strncmp(s, "tanh", 4))
        push(tanh(pop()));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 == 0.0) {
        printf("error: zero divisor\n");
        break;
      }
      push(pop() / op2);
      break;
    case '%':
      op2 = pop();
      push((int)pop() % (int)op2);
      break;
    case '#':
      printf("\t%.8g\n", peek());
      entered = 1;
      break;
    case '&':
      duplicate();
      printf("\t%.8g\n", peek());
      entered = 1;
      break;
    case '~':
      swap();
      printf("\t%.8g\n", peek());
      entered = 1;
      break;
    case ':':
      clear();
      entered = 1;
      printf("\n");
      break;
    case '\n':
      if (entered == 0) {
        printf("\t%.8g\n", pop());
      }
      entered = 0;
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

#define MAXVAL 100

int stackpos = 0;
double stack[MAXVAL];

void push(double f) {
  if (stackpos >= MAXVAL) {
    printf("error: stack full can't push %g\n", f);
    return;
  }
  stack[stackpos++] = f;
}

double peek() {
  if (stackpos == 0) {
    printf("error: stack empty\n");
    return 0.0;
  }
  return stack[stackpos - 1];
}

void duplicate() {
  double val = peek();
  push(val);
}

void swap() {
  if (stackpos < 1) {
    printf("error: not enough values on stack to swap\n");
    return;
  }
  double val1 = pop();
  double val2 = pop();
  push(val1);
  push(val2);
}

void clear() {
  while (stackpos > 0) {
    pop();
    stackpos--;
  }
  printf("stack cleared\n");
}

double pop() {
  if (stackpos == 0) {
    printf("error: stack empty\n");
    return 0.0;
  }
  return stack[--stackpos];
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isalnum(c) && c != '.') {
    if (c == '-') {
      int nextChar = getch();
      ungetch(nextChar);
      if (!isdigit(nextChar)) {
        return c;
      }
    } else {
      return c;
    }
  }

  i = 0;
  if (isalpha(c)) {
    while (isalnum(s[++i] = c = getch()))
      ;

    s[i] = '\0';
    if (c != EOF) {
      ungetch(c);
    }
    return LIB_FN;
  }

  if (c == '-') {
    s[i] = '-';
    s[++i] = c = getch();
  }
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  s[i] = '\0';

  if (c != EOF) {
    ungetch(c);
  }

  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufpos = 0;

int getch(void) { return (bufpos > 0) ? buf[--bufpos] : getchar(); }

void ungetch(int c) {
  if (bufpos >= BUFSIZE) {
    printf("ungetch: too many characters\n");
    return;
  }
  buf[bufpos++] = c;
}
