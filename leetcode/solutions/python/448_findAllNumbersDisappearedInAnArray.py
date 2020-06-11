# Source: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
# Problem #: 448
# Author: Lily Yang
# Date: June 3, 2020
# Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/448.md

# SOLUTION WAS NOT ACCEPTED ON LEETCODE - NEEDS IMPROVEMENT

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        return [x for x in range(1, n + 1) if x not in nums]

def main():
  s = Solution()

  nums = [4, 3, 2, 7, 8, 2, 3, 1]

  # expected: [5, 6]
  print(s.findDisappearedNumbers(nums))

if __name__ == "__main__":
  main()