// Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Problem #: 442
// Author: Lily Yang
// Date: June 30, 2020
// Notes: (https://github.com/lilyyanglt/leetcode/blob/master/notes/422.md)

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> result;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++) {
            temp = abs(nums[i]);
            if (nums[temp-1] < 0) result.push_back(temp);
                nums[temp-1] *= -1;
        }
        
        return result;
    }
};


int main(void) {
  Solution *s = new Solution();

  // Test case #1: n = 8, expected output [2,3]

  std::vector<int> nums = {4,3,2,7,8,2,3,1};

  nums = s->findDuplicates(nums);

  assert(nums[0] == 2);
  assert(nums[1] == 3);


  // Test case #2: n = 1, expected output []

  std::vector<int> nums2 = {1};

  std::vector<int> nums2_result(s->findDuplicates(nums2));

  assert(nums2_result.size() == 0);


  // Test case #3: n = 2, expected output [2]

  std::vector<int> nums3 = {2,2};

  nums3 = s->findDuplicates(nums3);

  assert(nums3[0] == 2);

  std::cout << "passed all test cases\n";
  
  return 0;

}