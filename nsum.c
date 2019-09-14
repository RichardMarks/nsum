#include "nsum.h"

int nsum(int n, int* numbers) {
  if (n == 1) {
    return numbers[0];
  }
  int sum = 0;
  int i = 0;
  while (i < n) {
    sum += numbers[i];
    i++;
  }
  return sum;
}
