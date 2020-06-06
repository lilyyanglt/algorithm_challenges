# Source: https://leetcode.com/problems/happy-number/
# Problem #: 202
# Author: Lily Yang
# Date: May 31, 2020
# Notes: (https://github.com/lilyyanglt/leetcode/blob/master/notes/202.md

class Solution:

    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        else: 
            sum_list = []
            digits_list = sorted([int(x)**2 for x in str(n)])

            length = len(digits_list)

            while True:
                if digits_list[length - 1] == 1 and digits_list[length - 2] == 0:
                    return True
                else:
                    sum_of_digits = sum(digits_list)
                    if sum_of_digits in sum_list:
                        return False
                    else:
                        sum_list.append(sum_of_digits)
                        n = sum_of_digits
                        digits_list = sorted([int(x)**2 for x in str(n)])
                        length = len(digits_list)


def main():
    solution = Solution()

    print(solution.isHappy(99)) # this should be false


if __name__ == "__main__":
    main()