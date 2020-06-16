// source: Art of Algorithm book

#include <iostream>

int findGCD(int m, int n) {

  assert(m > 0);
  assert(n > 0);

  int r = m % n;  

  while (r != 0) {
    m = n;
    n = r;
    r = m % n;
  }

  return n;

}

// alternative algorithm

int findGCD1(int m, int n) {
  m = m % n;
  if (m == 0) return n;

  n = n % m;
  if (n == 0) return m;

  return findGCD1(m, n);
}

// alternative algorithm

int findGCD2(int m, int n) {
  
  assert(m > 0);
  assert(n > 0);
  
  int r = m % n;
  if (r == 0) return n;
  else return findGCD(n, r);

}

int main(int argc, char** argv) {
  
  int m, n;
  if (argc <= 2) {

    std::cout << "Enter 2 integers:\n";
    std::cin >> m >> n;
    printf("The GCD between %d and %d is %d", m, n, findGCD1(m, n));

  } else {

    m = atoi(argv[1]);
    n = atoi(argv[2]);
    printf("The GCD between %d and %d is %d\n", m, n, findGCD1(m, n));
  }

  return 0;

}