// Link: https://leetcode.com/problems/move-zeroes/
// Problem #: 283
// Author: Lily Yang
// Date: June 17, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/283.md

#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int zero_count = 0, n = nums.size();

        if(n==0 || n==1) return;

        for (int i=0; i<n; i++) {
            if(nums[i]==0) {
                zero_count++;
            } else {
                if(zero_count > 0) {
                    nums[i-zero_count] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
};

int main() {

  std::vector<int> nums = {5,1,3,0,23,10};
  
  Solution *s = new Solution();

  // test #1 - expect the original array to be this: 5, 1, 3, 23, 10, 0

  std::cout << "before moving zeros:\n";

  for (auto value : nums) {
      std::cout << value << " ";
  }

  s->moveZeroes(nums);

  std::cout << "\nafter moving zeros:\n";

  for (auto value : nums) {
      std::cout << value << " ";
  }

  std::cout << std::endl;

  return 0;

}