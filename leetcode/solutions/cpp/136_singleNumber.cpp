// Link: https://leetcode.com/problems/single-number/
// Problem #: 136
// Author: Lily Yang
// Date: June 15, 2020
// Notes: (https://github.com/lilyyanglt/leetcode/blob/master/notes/518.md

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int n = nums.size();
        
        if (n % 2 == 0) {
            return 0;
        } else {
            std::unordered_set<int> values;
            for(int x : nums) {
                
                // remove the current element from unordered set if it's already there
                if(values.count(x) == 1) {
                    values.erase(x);
                } else {
                    
                    // so my unordered set will end up with just the unique element
                    values.insert(x);
                }
            }
            
            // dereference the pointer to get the value of the first item in the unordered set
           return *values.begin(); 
        
        }
        
    }
};

int main(void) {

  std::vector<int> no_single_number = {2, 2, 1, 1};
  std::vector<int> single_number = {2, 2, 4, 3, 3};
  Solution *s = new Solution();

  // test #1 - test no_single_number - expecting zero
  std::cout << s->singleNumber(no_single_number) << std::endl;

  // test #2 - test with single_number - expecting 4
  std::cout << s->singleNumber(single_number) << std::endl;

  return 0;
}