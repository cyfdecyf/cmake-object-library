#include "lib1.h"

int l2(int i) {
  return i + 3;
}

int l2_call_l1(int i) {
  return l1_called(i + 4);
}

int l2_called(int i) {
  return l1(i + 5);
}

