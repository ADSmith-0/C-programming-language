#include <stdio.h>
#define MAX_LENGTH 1000

void getLine(char input[], int limit);
void escape(char input[], char escaped[]);
void unescape(char input[], char unescaped[]);

int main() {
  char input[MAX_LENGTH];
  getLine(input, MAX_LENGTH);

  char escaped[MAX_LENGTH];
  escape(input, escaped);

  char unescaped[MAX_LENGTH];
  unescape(input, unescaped);

  printf("before: %s,\nafter: %s\n", input, escaped);
  return 0;
}

void getLine(char input[], int limit) {
  char character;
  int i = 0;

  while ((character = getchar()) != EOF) {
    input[i++] = character;
  }

  input[i] = '\0';
}

void escape(char input[], char escaped[]) {
  int i, j;

  for (i = 0, j = 0; input[i] != '\0'; i++, j++) {
    switch (input[i]) {
    case '\n': {
      escaped[j++] = '\\';
      escaped[j] = 'n';
      break;
    }
    case '\t': {
      escaped[j++] = '\\';
      escaped[j] = 't';
      break;
    }
    default: {
      escaped[j] = input[i];
      break;
    }
    }
  }

  escaped[j] = '\0';
}

void unescape(char input[], char unescaped[]) {
  int i, j;

  for (i = 0, j = 0; input[i] != '\0'; i++, j++) {
    switch (input[i]) {
    case '\\': {
      char nextChar = input[++i];
      if (nextChar == 'n') {
        unescaped[j] = '\n';
        break;
      }

      if (nextChar == 't') {
        unescaped[j] = '\t';
        break;
      }
    }
    default: {
      unescaped[j] = input[i];
      break;
    }
    }
  }

  unescaped[j] = '\0';
}
