/*
* Fibonacci sequence learnings from CTCI
* Date: July 13, 2020
*/

#include <iostream>
#include <vector>

/* -------------------------------------------------------------------------
*  recursive approach
*  time complexity: O(2^n) - 0 <= n <= k, k is all natural numbers
*  space complexity: O(1)
-------------------------------------------------------------------------*/

int fib_recursive(int n) {
  // base case
  if (n <= 0) return 0;
  if (n == 1) return 1;

  return fib_recursive(n-1) + fib_recursive(n-2);
}

/* -------------------------------------------------------------------------
*  iterative approach
*  time complexity: O(n) - 0 <= n <= k, k is all natural numbers
*  space complexity: O(1)
-------------------------------------------------------------------------*/
int fib_iterative(int value) {
  
  if (value == 0) return value;
  int a = 0, b = 1, current=0;

  for (int i=2; i<value; i++) {
    current = a + b;
    a = b;
    b = current;
  }

  return a + b;
}

/* -------------------------------------------------------------------------
*  memoization approach
*  time complexity: O(n) - 0 <= n <= k, k is all natural numbers
*  space complexity: O(n)
-------------------------------------------------------------------------*/

int fib_memo(int value, std::vector<int>& cache) {
    if (value == 0 || value == 1) return value;
    if (cache[value] == -1) {
      cache[value] = fib_memo(value-1, cache) + fib_memo(value-2, cache);
    }
    
    return cache[value];
}

int fib_memo(int value) {
  std::vector<int> memo(value+1, -1);

  return fib_memo(value, memo);
}


// drives the program
int main(int argc, char *argv[]) {

  int value;
  if (argv[1] == NULL) {
    value = 5;
  } else {
    value = atoi(argv[1]);
  }

  std::cout << fib_recursive(value) << std::endl;
  std::cout << fib_iterative(value) << std::endl;
  std::cout << fib_memo(value) << std::endl;

  return 0;
} 