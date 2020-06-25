# Source: https://leetcode.com/problems/find-the-duplicate-number/
# Problem #: 287
# Author: Lily Yang
# Date: June 25,2020
# Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/287.md)

import doctest

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        """
        >>> findDuplidate([3, 1, 3, 2, 4])
        >>> 3
        """
        
        nums.sort();
        n = len(nums);
        unique = 0;
        
        for i in range(n-1):
            if nums[i] == nums[i+1]:
                unique = nums[i]
        
        return unique;


def main():
  doctest.testmod()

  s = Solution()

  # expect 3
  print(s.findDuplicate([3,1,3,2,4]))

if __name__ == "__main__":
  main()