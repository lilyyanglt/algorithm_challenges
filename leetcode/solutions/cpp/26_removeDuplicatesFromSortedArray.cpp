/* Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Problem #: 26
 * Author: lily yang
 * Date: Aug 27, 2020

 * Approach:
  - I am using a position pointer to always point to the position I need to update if the values at nums[i] != nums[i+1].
  - If the values at nums[i] != nums[i+1]
    - I need to check if pos == i + 1, if yes, it means that there hasn't been any duplicates, so I don't do anything here other than moving incrementing the pos index
    - If pos is less than i + 1, then I know for sure there's been duplicates in the front of the array, so update nums[pos] = nums[i+1]
  - ultimately, my pos will be the total unique elements in the array

*/ 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        // starting pos for the update is 1 because the first value will always be in the right spot
        // since it's sorted
        int pos = 1;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] != nums[i+1]) {
                if (pos < i + 1) {
                    nums[pos] = nums[i+1];
                }
                pos++;
            }
        }
        
        return pos;
    }
};