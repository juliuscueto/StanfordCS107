#include <stdio.h>
#include <string.h>
#include <iostream>


void *lsearch(void *key, void *base, int n, int elemSize,
              int (*cmpfn)(void *, void *)) {
  for (int i = 0; i < n; i++) {
    void *elemAddr = (char *)base + i * elemSize;
    if (cmpfn(key, elemAddr) == 0) {
      return elemAddr;
    }
  }
  return NULL;
}

int mycmpfn(void *s1, void *s2) { return memcmp(s1, s2, sizeof(int)); }

int main(int argc, char const *argv[]) {
  int a = 5;
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *addr = (int*) lsearch(&a, arr, 10, sizeof(int), mycmpfn);
  printf("%d\n", *addr);
  *addr = 10;
  printf("%d\n", *addr);
  for (auto i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n" << std::endl;
  return 0;
}
