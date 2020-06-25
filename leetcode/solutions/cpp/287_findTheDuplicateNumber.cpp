// Link: https://leetcode.com/problems/find-the-duplicate-number/
// Problem #: 287
// Author: Lily Yang
// Date: June 25, 2020
// Notes: (https://github.com/lilyyanglt/leetcode/blob/master/notes/287.md)

#include <iostream>
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i=0; i<n-1; i++) {
            if (nums[i] == nums[i+1]) return nums[i];
        }
        
        return 0;
    }
};

// drives the program
int main(void) {
  
  std::vector<int> nums = {3, 1, 3, 2, 4};
  Solution *s = new Solution();

  // test case #1 - return 3
  std::cout << s->findDuplicate() << std::endl;

  return 0;
}