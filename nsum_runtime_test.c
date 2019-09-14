#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "nsum.h"

int main() {
  int n = 0;
  printf("NSUM v1.1 Runtime Test\nEnter Count of Numbers to Sum: ");
  scanf("%d", &n);
  if (n == 0) {
    return 0;
  }
  printf("Enter %d %s:\n", n, n == 1 ? "number" : "numbers");

  int* numbers = (int*)malloc(sizeof(int) * n);

  int i = 0;
  for (i = 0; i < n; i++) {
    printf("Number %d/%d: ", (i + 1), n);
    scanf("%d", &numbers[i]);
  }

  void* nsum_handle = dlopen("libnsum.1.0.dylib", RTLD_LAZY | RTLD_LOCAL);
  if (nsum_handle == 0) {
    fprintf(stderr, "An error occurred:\n%s\n", dlerror());
    exit(EXIT_FAILURE);
    return 1;
  }

  int (*nsum)(int,int*) = dlsym(nsum_handle, "nsum");
  if (nsum == 0) {
    fprintf(stderr, "An error occurred:\n%s\n", dlerror());
    exit(EXIT_FAILURE);
    return 1;
  }

  int sum = nsum(n, numbers);

  printf("The sum is %d\n", sum);

  if (numbers != 0) {
    free(numbers);
    numbers = 0;
  }

  if (dlclose(nsum_handle) != 0) {
    fprintf(stderr, "An error occurred:\n%s\n", dlerror());
    exit(EXIT_FAILURE);
    return 1;
  }

  return 0;
}
