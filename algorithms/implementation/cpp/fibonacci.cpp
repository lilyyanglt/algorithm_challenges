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
  int current, prev = 1, prev_prev = 0;

  for (int i=1; i<value; i++) {
    current = prev + prev_prev;
    prev_prev = prev;
    prev = current;
  }

  return current;
}

/* -------------------------------------------------------------------------
*  memoization approach
*  time complexity: O(n) - 0 <= n <= k, k is all natural numbers
*  space complexity: O(n)
-------------------------------------------------------------------------*/

int fib_memo(int value) {
  std::vector<int> memo(value, -1);

  if (value <=0) return 0;
  else if (value == 1) return 1;
  else if (memo[value] > 0) return memo[value];

  memo[value] = fib_memo(value - 1) + fib_memo(value - 2);

  return memo[value];
}


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