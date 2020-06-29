// Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Problem #: 448
// Author: Lily Yang
// Date: June 29,2020
// Notes: (https://github.com/lilyyanglt/leetcode/blob/master/notes/448.md

#include <iostream>
#include <vector>

class Solution {
  public:
      std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
          std::vector<int> output;
          int n = nums.size(), temp = 0;
          
          // mark the indexes that we already saw by changing them negative
          for (int i = 0; i < n; i++) {
              temp = abs(nums[i]);
              nums[temp-1] = abs(nums[temp-1]) * -1;
          }
          
          // loop through to find which index hasn't been marked
          for (int i = 0; i < n; i++) {
              if (nums[i] > 0) output.push_back(i+1);
          }
          
          return output;
      }
};

// drives the program
int main(void) {
  
  Solution *s = new Solution();

  std::vector<int> nums = {4,3,2,7,8,2,3,1};

  nums = s->findDisappearedNumbers(nums);

  assert(nums[0] == 5);
  assert(nums[1] == 6);

  // if the test passes, it will reach this line

  std::cout << "passed\n";

  return 0;
}