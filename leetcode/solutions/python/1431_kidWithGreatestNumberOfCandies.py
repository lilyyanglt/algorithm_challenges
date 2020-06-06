# Source: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
# Problem #: 1431
# Author: Lily Yang
# Date: May 25, 2020
# Notes: https://github.com/lilyyanglt/leetcode/blob/master/notes/1431.md

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


def main():
    solution = Solution()

    print(solution.kidsWithCandies([4, 2, 5, 6], 3))


if __name__ == "__main__":
    main()