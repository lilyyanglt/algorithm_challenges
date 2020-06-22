// Link: https://leetcode.com/problems/single-number-ii/
// Problem #: 137
// Author: lily yang
// Date: June 22, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/137.md)


#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
    
        int n = nums.size();
        
        // if the length is less than 3, then for sure there's no unique value
        if (n < 3) return 0;

        std::sort(nums.begin(), nums.end());
        for (int i=0; i<n; i=i+3) {
            if (i == n-1 || nums[i] != nums[i+1]) return nums[i];
        }
        
        return 0;
    }
};

int main(void) {

  std::vector<int> arr1 = {3,3,3,2};
  std::vector<int> arr2 = {0,1,0,1,0,1,99};
  std::vector<int> arr3 = {1};
  std::vector<int> arr4 = {3, 3, 3, 6, 6, 6};

  Solution *s = new Solution();

  // test #1 - expecting 2
  std::cout << s->singleNumber(arr1) << std::endl;

  // test #2 - expecting 99
  std::cout << s->singleNumber(arr2) << std::endl;

  // test #3 - expecting 0
  std::cout << s->singleNumber(arr3) << std::endl;

  // test #4 - expecting 0
  std::cout << s->singleNumber(arr4) << std::endl;

  return 0;
}