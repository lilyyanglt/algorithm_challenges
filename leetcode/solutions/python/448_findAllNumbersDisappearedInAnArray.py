# Source: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
# Problem #: 448
# Author: Lily Yang
# Date: June 3, 2020
# Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/448.md

import unittest

class Solution:
    def findDisappearedNumbers(self, nums):
        output = []

        for value in nums:
          value = abs(value)
          nums[value-1] = abs(nums[value-1]) * -1

        for i, value in enumerate(nums):
          if value > 0:
            output.append(i + 1)
        
        return output


class TestFindDisappearedNumbers(unittest.TestCase):
  
  def setUp(self):
    self.s = Solution()

  def test_A(self):
    nums = [4,3,2,7,8,2,3,1]
    actual = self.s.findDisappearedNumbers(nums)
    expected = [5,6]
    self.assertEqual(actual, expected)


if __name__ == "__main__":
  unittest.main();