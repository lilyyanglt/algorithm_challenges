# [Sum of Digits](https://www.codewars.com/kata/541c8630095125aba6000c00)

## Goal
Given n, take the sum of the digits of n. If the sum has more than one digit, continue reducing it in this manner until a single-digit number is produced. This is only applicable to real numbers.

Input: 
5
16
493193

Output:
5 --> 5
16 --> 1 + 6 = 7
493193 --> 4 + 9 + 3 + 1 + 9 + 3 = 29 --> 1 + 1 -- > 2

## Pseudocode
1. if n < 10 return n
2. else:
3.   while n is not zero
4.  sum = sum + last digit of n % 10
5.  update n with n / 10
6. Call the procedure recursively by using the new sum as the parameter

## Complexity Analysis

Time Complexity:
  - x is the length of n 
  T(x) = c1 + c2 + (c3 * x) + <span style="color:red">T(x)?</span>
  <span style="color:red">I AM ACTUALLY NOT SURE</span>

Space Complexity:
- O(1)

## Outcome

__cpp__
```cpp
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

```

## Other solutions and learnings

* This person here is so clever and they solved it in constant time
* This solution works on the fact that the recursive sum of digits of a multiple of 9 is always between 1 - 9

e.g. 
intput: 999999999999
output: 9 + 9 + 9...+ 9 -> 108 -> 1 + 0 + 8 -> 9

input: 76543298648954
output: 7 + 6...+ 4 -> 80 -> 8 + 0 -> 8

so you see, the sum always ends up to be between 1 - 9. I am not really sure still if i understood this completely, but amazing and smart solution. 
__cpp__
```cpp

// author: https://www.codewars.com/users/__Anonymous__

int digital_root(int Z) {
  return --Z % 9 + 1;

  // return (n % 9 == 0 && n != 0)? 9 : n % 9

}
```



