// Link: https://leetcode.com/problems/rotate-array/solution/
// Problem #: 189
// Author: lily yang
// Date: June 24, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/189.md)

#include <iostream>
#include <vector>

class Solution {

  // this is the solution using extra memory

  public: 
    void rotate(std::vector<int>& nums, int k) {
      std::vector<int> output(nums);
      int n = nums.size();
      k %= n;

      if(k == 0) return;

      for(int i=0; i<n; i++) {
        nums[(i+k)%n] = output[i];
      }
    }

  // TODO: need to include solution for using O(1) space here
};

int main() {

  Solution *s = new Solution();

  std::vector<int> nums = {-1,-100,3,99}; // even elements
  std::vector<int> nums2 = {1,2,3,4,5,6,7}; // odd elements

  // test 1 - expect original nums to become [5,6,7,1,2,3,4] when k = 3

  s->rotate(nums2, 3);

  for (auto it = nums2.begin(); it != nums2.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << std::endl;

  // test 2 - expect original items to become [3,99,-1,-100]
  s->rotate(nums, 2);

  for (auto it = nums.begin(); it != nums.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << std::endl;



  return 0;
}
