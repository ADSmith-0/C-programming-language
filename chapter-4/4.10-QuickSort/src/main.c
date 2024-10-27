#include "quicksort.h"
#include <stdio.h>
#define ARR_LENGTH 9

int main() {
  int arr[ARR_LENGTH + 1] = {1, 5, 10, 3, 8, 7, 2, 6, 9};
  int i;

  for (i = 0; arr[i] != '\0'; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  quicksort(arr, 0, ARR_LENGTH);

  for (i = 0; arr[i] != '\0'; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
