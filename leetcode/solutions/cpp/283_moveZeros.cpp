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

    /*
      Sept 10, 2020 - second approach that I've come up with and it only took 4 ms faster than any other solutions I've implemented.

       // TASK IS TO SORT THE ZEROS TO THE RIGHT SIDE.
        
      /* 
       Questions to ask:
        - will the non zero elements have negative values? 
        - am i allowed to change the relative order of the non-zero elements?
        - are there any other restrictions as to additional memory usage or others?
        - am i allowed to make a copy of the array to 
        
        Assuming that non zero elements will have negative values, and I can't change the relative order of the non-zero elements
        
        test cases:
        [] or [1 element] -> do nothing - return
        [0, 1, 0, -2, 3, 4] -> [1, -2, 3, 4, 0, 0]
        [0, 0, 0, 2, 1, 5] -> [2, 1, 5, 0, 0, 0]
        [2, 1, 5, 0, 0, 0] -> [2, 1, 5, 0, 0, 0]
        [1, 0, -1, 3, 0] -> [1, -1, 3, 0, 0]
        
        INITIAL PSEUDOCODE
        
        zeroIndex = -1 // this means no zeros present
        n = nums.size()
        for i <- 0 to n - 1 do // n is the size of nums
            if nums[i] == 0 and zeroIndex == -1 do
                zeroIndex = i
            else if nums[i] != 0 and zeroIndex != -1 do
                swap(nums[i], nums[zeroIndex])
                zeroIndex++ // 
        
        
        UPDATED PSEUDOCODE TO REDUCE THE NUMBER OF OPERATIONS
        
        1. find the first zero index
        for i <- 0 to n-1 do 
            if nums[i] == 0 do
                zeroIndex = i
                break
                
        if zeroIndex != -1 do
            for i <- zeroIndex to n - 1
                if nums[i] != 0
                    swap(nums[i], nums[zeroIndex])
                    zeroIndex++
        else return // ie: no zeros were found


    */
    void moveZeros2(std::nums<int>& nums) {
        int n = nums.size(), zeroIndex = -1;
        
        if (n > 1) {
            
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    zeroIndex = i;
                    break;
                }
            }
            
            if (zeroIndex != -1) {
                for (int i = zeroIndex; i < n; i++) {
                    if (nums[i] != 0) {
                        swap(nums[i], nums[zeroIndex]);
                        zeroIndex++;
                    }
                } 
            } else {
                return;
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