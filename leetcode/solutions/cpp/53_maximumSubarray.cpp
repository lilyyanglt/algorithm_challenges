// Link: https://leetcode.com/problems/maximum-subarray/
// Problem #: 53
// Author: Lily Yang
// Date: June 16, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/53.md

#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
            
        int n = nums.size();
        
        if (n == 1) return nums[0];
        else {
            // I have to initiate max_sum as some really small negative value
            // C++ has a built in macro for the smallest negative value
            // sometimes it depends on the compiler the smallest value might be -2^63 for a 64 bit integer or -2^31 for a 32 bit integer
            int max_sum = INT_MIN, current_sum = 0;
            
            for (int i = 0; i < n; i++) {
                current_sum += nums[i];
                
                if(current_sum > max_sum) {
                    max_sum = current_sum;
                }
                
                if(current_sum < 0) {
                    current_sum = 0;
                }
            }
            
            return max_sum;
        }
        
    }
};

int main() {

  std::vector<int> all_pos = {1,2,3,4,5,6,7};
  std::vector<int> all_neg = {-2,-8,-1,-2,-10};
  std::vector<int> mix_neg_pos = {-2,1,-3,4,-1,2,1,-5,4};
  
  Solution *s = new Solution();

  // test #1 - expected 28 to be returned

  std::cout << s->maxSubArray(all_pos) << std::endl;

  // test #2 - expecting -1 to be returned
  std::cout << s->maxSubArray(all_neg) << std::endl;

  // test #3 - expecting 6 to be returned
  std::cout << s->maxSubArray(mix_neg_pos) << std::endl;

  return 0;

}