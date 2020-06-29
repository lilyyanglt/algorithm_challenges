# Source: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
# Problem #: 1431
# Author: Lily Yang
# Date: May 25, 2020
# Notes: https://github.com/lilyyanglt/leetcode/blob/master/notes/1431.md

import unittest

class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        
        # find the current max value in the candies array
        greatest = max(candies)
        output = []
        for candies_total in candies:
            output.append(False) if candies_total + extraCandies < greatest else output.append(True)
                
        return output


class TestKidsWithCandies(unittest.TestCase):

    def setUp(self):
        self.s = Solution();

    def test_A(self):
        candies = [2,3,5,1,3]
        extraCandies = 3
        actual = self.s.kidsWithCandies(candies, extraCandies)
        expected = [True, True, True, False, True]
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main();