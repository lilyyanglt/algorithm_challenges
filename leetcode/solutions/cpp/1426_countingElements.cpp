// Link: https://leetcode.com/problems/counting-elements/
// Problem #: 1426
// Author: lily
// Date: June 21, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/1426.md


#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int countingElements(std::vector<int>& arr) {
        std::unordered_set<int> s;
        int n = arr.size(), count = 0, sum = 0;
        
        if (n == 1) return 0;

        for (int value : arr) {
          s.insert(value);
        }

        for (int value : arr) {
          sum = value + 1;
          if (s.find(sum) != s.end()) {
            count++;
          } 
        }

        return count;
    }
};

int main(void) {

  std::vector<int> arr1 = {1, 2, 3};
  std::vector<int> arr2 = {1, 3, 3, 5, 7, 7};
  std::vector<int> arr3 = {1, 3, 2, 3, 5, 0};
  std::vector<int> arr4 = {1, 1, 2, 2, 3, 4, 6, 7, 7};
  std::vector<int> arr5 = {1};

  Solution *s = new Solution();

  // test #1 - expecting 2
  std::cout << s->countingElements(arr1) << std::endl;

  // test #2 - expecting 0
  std::cout << s->countingElements(arr2) << std::endl;

  // test #3 - expecting 3
  std::cout << s->countingElements(arr3) << std::endl;

  // test #4 - expecting 6
  std::cout << s->countingElements(arr4) << std::endl;

  // test #5 - expecting 0
  std::cout << s->countingElements(arr5) << std::endl;

  return 0;
}