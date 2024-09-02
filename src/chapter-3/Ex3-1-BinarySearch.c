#include <stdio.h>
#include <time.h>
#define MAX_LENGTH 10000

void fill(int arr[], int length);
int BinarySearch(int x, int arr[], int arrSize);
int BinarySearch2(int x, int arr[], int arrSize);

int main() {
  int arr[MAX_LENGTH];
  fill(arr, MAX_LENGTH);

  int find = 9523;

  clock_t begin1 = clock();
  printf("index: %d\n", BinarySearch(find, arr, MAX_LENGTH));
  clock_t end1 = clock();
  clock_t begin2 = clock();
  printf("index: %d\n", BinarySearch(find, arr, MAX_LENGTH));
  clock_t end2 = clock();
  printf("BinarySearch: %f, BinarySearch2: %f\n",
         (double)(end1 - begin1) / CLOCKS_PER_SEC,
         (double)(end2 - begin2) / CLOCKS_PER_SEC);

  return 0;
}

void fill(int arr[], int length) {
  for (int i = 0; i < length - 1; i++) {
    arr[i] = i;
  }
}

int BinarySearch(int x, int arr[], int arrSize) {
  int low, mid, high;
  low = 0;
  high = arrSize - 1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (x < arr[mid]) {
      high = mid - 1;
    } else if (x > arr[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int BinarySearch2(int x, int arr[], int arrSize) {
  int low, mid, high;
  low = 0;
  high = arrSize - 1;

  while (low <= high && x != arr[mid]) {
    mid = (low + high) / 2;

    if (x < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return (x == arr[mid]) ? mid : -1;
}
