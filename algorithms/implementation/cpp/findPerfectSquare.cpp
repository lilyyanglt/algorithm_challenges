/*
* Finding the perfect square of an integer
* Returns -1 if there's no perfect square of the number
* Learnings from CTCI
* Date: July 21, 2020
*/

#include <iostream>


int sqrt_helper(const int n, int min, int max) {
  // base case of the recursive function
  
  printf("min is %d, max is %d\n", min, max);
  if (min > max) return -1; // no perfect square of n

  int guess = (max + min) / 2;
  if (guess * guess == n) return guess; // found the perfect square
  
  // too high, so we'll try a lower number
  else if (guess * guess > n) return sqrt_helper(n, min, guess - 1); 
  
  // too low, so we'll try a higher value
  else return sqrt_helper(n, guess + 1, max);
}

// RECURSIVE APPROACH
int sqrt_recursive(int n) {
  return sqrt_helper(n, 1, n);
}

int sqrt_iterative(int n) {
  for(int guess = 1; guess * guess <= n; guess++) {
    printf("guess is %d\n", guess);
    if(guess*guess == n) {
      return guess;
    }
  }

  return -1;
}

int main(void) {

  printf("Recursive solution: %d\n", sqrt_recursive(99));
  printf("Iterative solution: %d\n", sqrt_iterative(99));

  return 0;
}