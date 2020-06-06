#include <iostream>
#include <math.h>

int digital_root(int n)
{
    if (n < 10) return n;
    
    int sum = 0;
    while (n) {
      sum = sum + (n % 10);
      // floor function is from math.h library
      n = floor(n/10);
    }
    
    return digital_root(sum);
}

int main() {
  digital_root(16);
  return 0;
}