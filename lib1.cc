#include "lib2.h"

int l1(int i) {
  return i + 1;
}

int l1_call_l2(int i) {
  return l2_called(i + 2);
}

int l1_called(int i) {
  return l2(i + 3);
}

