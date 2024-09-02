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

  printf("before: %s,\nafter: %s\n", input, unescaped);
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
  int j = 0;

  for (int i = 0; input[i] != '\0'; i++) {
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

    j++;
  }

  escaped[j] = '\0';
}

void unescape(char input[], char unescaped[]) {
  int j = 0;

  for (int i = 0; input[i] != '\0'; i++) {
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

    j++;
  }

  unescaped[j] = '\0';
}
