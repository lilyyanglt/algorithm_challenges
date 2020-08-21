""" 
Source: https://leetcode.com/problems/happy-number/
Problem #: 202
Author: Lily Yang
Date: May 31, 2020

Approach 1:
* Using extra memory to track the index of the odd values - oddIndex
* If the value is even and the oddIndex is empty, do nothing
* If the value is even and the oddIndex is not empty
  * oddIndex -> the first value in odd index
  * swap arr[oddIndex] with arr[evenIndex]
  * add the evenIndex into oddIndex array after swap

* Time Complexity: O(n) - n being the number of elements in the 
  non sorted arr
* Space Complexity: O(n) - worst case if all the elements in 
  non sorted arr is odd

Approach 2: (Optimization)
* This approach is similar to the first except I won't be needing
  extra space, because I realized that if I just use one 
  variable to track the index of the latest odd value, and once
  I do a swap, I increment the odd value by 1, then I don't need
  extra space

* Time Complexity: O(n)
* Space Complexity: O(1)

"""
import unittest


def sortArrayByParity(A: list) -> list:
    if len(A) < 2: return A
    
    odd = -1
    for index, value in enumerate(A):
        if value % 2 != 0:
            if odd < 0:
                odd = index
        else:
            # Swap current value with the value at odd index
            A[odd], A[index] = A[index], A[odd]
            odd += 1
    
    return A


class TestSortArrayByParity(unittest.TestCase):
  
  def test_A(self):
    unsorted = [3,1,2,4]
    actual = sortArrayByParity(unsorted)
    expected = [[2,4,1,3], [4,2,3,1], [4,2,1,3], [2,4,3,1]]
    self.assertTrue(actual in expected)

  def test_B(self):
    unsorted = []
    actual = sortArrayByParity(unsorted)
    # empty lists are false
    self.assertFalse(actual)

  def test_C(self):
    unsorted = [1]
    actual = sortArrayByParity(unsorted)
    expected = [1]
    self.assertEqual(actual, expected)
  

if __name__ == "__main__":
  unittest.main()


