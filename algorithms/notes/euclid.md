# Euclid Algorithm
> source: Art of Programming - Volumn 1 - 1.1

- This is an algorithm that is used to find the GCD between 2 numbers


## Problem Statement
- Given value m and n where m > 0 and n > 0, find the greatest Greatest Common Divisor (the latest positive integer that evenly divides both m and n)


## Algorithm

1. find remainder r <- m % n (0 <= r < n)
1. is r 0? if yes, return n (n is the answer)
1. else repeat step 1 using m <- n, n <- r 

## Implementation approach and Complexity Analysis

> source: https://stackoverflow.com/questions/18137019/running-time-of-gcd-function-recursively-euclid-algorithm
> source: https://stackoverflow.com/questions/3980416/time-complexity-of-euclids-algorithm

### Recursion

* Running time:
* Space:

```cpp

int findGCD(int m, int n) {
  
  assert(m > 0);
  assert(n > 0);
  
  int r = m % n;
  if (r == 0) return n;
  else return findGCD(n, r);
}

// alternatively to reduce having to replace m with n

int findGCD1(int m, int n) {
  m = m % n;
  if (m == 0) return n;

  n = n % m;
  if (n == 0) return m;

  return findGCD1(m, n);
}
```

### Iteration

* Running time:
* Space:

```cpp

int findGCD(int m, int n) {

  assert(m > 0);
  assert(n > 0);

  int r = NULL;  

  while (r != 0) {
    m = n;
    n = r;
    r = m % n;
  }

  return n;

}
```

