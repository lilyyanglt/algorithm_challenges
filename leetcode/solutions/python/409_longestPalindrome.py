"""
Aug 14, 2020
Author: Lily Yang
Total time taken: 45 minutes
Leetcode #409 (https://leetcode.com/problems/longest-palindrome/)

Approach:
The definition of a Palindrome is when there's an even number of the same
character, plus 1 additional character for strings that are odd and for strings
that are even numbered there shouldn't be any odd count of characters, so using
this definition. I can keep track of the total number of each character in a 
hashmap:
* if there's no single different characters (ie. all characters appear
even number of times and no letter that is appearing odd number of times), 
then I can just add up the value of each of the keys in the hashmap

e.g {
      a: 4,
      b: 2,
      c: 4
    }
  
    This is a total 4 + 2 + 4

* if there's single characters that appears once or characters with odd appearances > 1
then, I will take the odd appearances greater than 1 subtract 1 if it's odd, if it's even just leave it

e.g {
      a: 5,
      b: 2,
      c: 1
      d: 1
      e: 1
    }

    then the sum of this would be (5 - 1) + (2) + 1

Time Complexity: O(N) - with N being the length of the string
Space Complexity: O(U) - with U being the number of uniqueue characters

"""

import unittest

def longestPalindrome(s: str) -> int:
    
    if len(s) == 0: return 0

    hashMap = {letter: 0 for letter in s}
    sum = 0
    isOdd = False
    
    for letter in s:
        hashMap[letter] = hashMap[letter] + 1
    
    for value in hashMap.values():
        if value > 1 and value % 2 != 0:
            sum += (value - 1)
            isOdd = True
        elif value > 1 and value % 2 == 0:
            sum += value
        else:
            isOdd = True
            
    return sum + 1 if (isOdd) else sum


class TestLongestPalindrome(unittest.TestCase):

  def test_A(self):
    s = [longestPalindrome('abccccdd'), 
    longestPalindrome('aaabbbcdefg'), 
    longestPalindrome('bb')]
    expected = [7, 5, 2]
    for s, value in zip(s, expected):
      self.assertEqual(s, value)
   
  def test_B(self):
    s = 'abccccdd'
    actual = longestPalindrome(s)
    self.assertEqual(actual, 7)

  def test_C(self):
    s = ''
    actual = longestPalindrome(s)
    self.assertEqual(actual, 0)


if __name__ == "__main__":
  unittest.main()