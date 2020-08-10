// Link: https://leetcode.com/problems/excel-sheet-column-number/
// Problem #: 171
// Author: lily yang
// Date: Aug 10, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/171.md)

#include <iostream>
#include <string>

class Solution {
public:
    int titleToNumber(const std::string& s) {
        
        int n = s.length();
        if (n == 0) return 0;
        
        // using 16 bytes to prevent potential overflow
        long long power = 1; // this is like 26^0 is my initial power
        long long sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += ((int)(s[i]) - 64) * power;
            // second loop will be 26^1...and so on 
            power*=26;
        }
        
        return sum;
    }
};

int main() {

  Solution s;

  // test 1 - expect 28
  std::cout << s.titleToNumber("AB") << std::endl;

  // test 2 - expect 0
  std::cout << s.titleToNumber("") << std::endl;

  // test 3 - expect 701
  std::cout << s.titleToNumber("ZY") << std::endl;


  return 0;
}
