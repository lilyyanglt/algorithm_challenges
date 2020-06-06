# Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
# Problem #: 26
# Author: Lily Yang
# Date: May 30, 2020
# Notes: https://github.com/lilyyanglt/leetcode/blob/master/notes/26.md


class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        try:
            nums_copy = list(nums)
        except TypeError as e:
            print(e)
            return 0
        else:
            last_element_index = len(nums) - 1

            for index, value in enumerate(nums_copy):
                if index != last_element_index and value == nums_copy[index + 1]:
                    nums.remove(value)

            return len(nums)


        # ALTERNATE SOLUTION
        # unique_count = 1
        # last_index = len(nums) - 1
        # for index, value in enumerate(nums):
        #     if index != last_index and value != nums[index + 1]:
        #         unique_count += 1
        #
        # return unique_count


def main():
    solution = Solution()

    print(solution.removeDuplicates([1, 1, 1, 1, 1, 2, 2, 2, 3]))


if __name__ == "__main__":
    main()