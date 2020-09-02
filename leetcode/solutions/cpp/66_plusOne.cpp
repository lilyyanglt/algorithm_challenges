/* Link: https://leetcode.com/problems/plus-one/
 * Author: lily yang
 * Date: Sept 2, 2020

 * Approach:
           edge cases for testing:
           
           [9] -> [1, 0]
           [9, 9] -> [1, 0, 0]

           everything else we can just modify the existing array
           
           [8,9] -> [9,0]
          
        // loop through array i <- length-1 to 0
        // if digits[i] < 9 then digits[i]++ and return digits
        // else set digits[i] = 0, i--
        
        // once I've looped through the whole list if code reaches here
        // it means that currently the digits array is all zero's
        // make digits[0] = 1, then append to end of array another zero
        // return digits

  Time Complexity: O(n)
  Space: O(1)

*/ 

#include <iostream>
#include <vector>

typedef std::vector<int> v;

v plusOne(v& digits) {

  int size = digits.size();

        for (int i=size-1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
}


int main(void) {

  v digits = {9, 9, 9};
  v expected = {1, 0, 0, 0};
  v actual;

  actual = plusOne(digits);

  for (int i = 0; i < expected.size(); i++) {
    assert(expected[i] == actual[i]);
  }

  printf("passed all tests\n");

  return 0;
}