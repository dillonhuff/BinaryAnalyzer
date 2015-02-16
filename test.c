struct {
  int some;
  double* more;
  char** names;
} a_random_struct;

int testFunc1(int i, int j) {
  return i*j + j;
}

void anotherTest(double x, double* y) {
  int i = x / 2;
  while (i < *y*2) {
    *y += 1;
    i--;
  }
}

int main() {
  int i, j;
  i = 0;
  j = 123;
  return testFunc1(i, j);
}
