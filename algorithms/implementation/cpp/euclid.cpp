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

int main(int argc, char** argv) {
  
  int m, n;
  if (argc <= 2) {

    std::cout << "Enter 2 integers:\n";
    std::cin >> m >> n;
    printf("The GCD between %d and %d is %d", m, n, findGCD(m, n));

  } else {

    m = atoi(argv[1]);
    n = atoi(argv[2]);
    printf("The GCD between %d and %d is %d\n", m, n, findGCD(m, n));
  }

  return 0;

}