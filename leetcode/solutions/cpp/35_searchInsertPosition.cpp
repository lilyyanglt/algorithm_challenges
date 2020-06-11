// Link: https://leetcode.com/problems/search-insert-position/submissions/
// Problem #: 35
// Author: Lily Yang
// Date: June 11, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/35.md
#include <iostream>
#include <vector>


class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        
        int n = nums.size();
        
        if (n == 0) return 0;
        if (nums[n-1] < target) return n;
        
        for (int i=0; i<nums.size(); i++) {
            if(target == nums[i] || nums[i] > target) return i;
        }
        
        return n;
    }
};

int main(void) {

  std::vector<int> nums{1, 3, 5, 60};

  
  Solution *s = new Solution();

  // test #1 - target is inside the list
  // this should print 2
  std::cout << s->searchInsert(nums, 5) << '\n';

  // test #2 - target is not in array, but should be inserted in middle
  // this should print 1
  std::cout << s->searchInsert(nums, 2) << '\n'; 

  // test #3 - target is not in array, but should be inserted as the first element
  // this shold print 0
  std::cout << s->searchInsert(nums, 0) << '\n';

  // test #4 - target is not in array, but should be inserted as last element
  // this should print 4
  std::cout << s->searchInsert(nums, 90) << '\n';

  return 0;
}