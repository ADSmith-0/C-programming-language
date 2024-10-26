#include "quicksort.h"

static void swap(int v[], int i, int j);

void quicksort(int v[], int left, int right) {
  int i, last;

  if (left >= right) {
    return;
  }
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (v[i] < v[left]) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  quicksort(v, left, last - 1);
  quicksort(v, left + 1, right);
}

static void swap(int v[], int i, int j) {
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
