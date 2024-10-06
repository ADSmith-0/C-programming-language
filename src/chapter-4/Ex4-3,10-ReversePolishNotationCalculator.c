#include <stdio.h>
#include <stdlib.h>

#define MAX_OP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main() {
  int type;
  double op2;
  char s[MAX_OP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
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
    case '\n':
      printf("\t%.8g\n", pop());
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
  if (!isdigit(c) && c != '.') {
    return c;
  }

  i = 0;
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
