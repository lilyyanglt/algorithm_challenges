// Link: https://leetcode.com/problems/power-of-two/
// Problem #: 231
// Author: Lily Yang
// Date: June 9, 2020
// Notes: (https://github.com/lilyyanglt/leetcode/blob/master/notes/518.md

#include <math.h>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n == 1) return true;
        if (n == 0 || n % 2 != 0) return false;
        
        return isPowerOfTwo(floor(n/2));
        
    }
};

int main(void) {

  
  Solution *s = new Solution();

  // test #1 - expecting a 1 - true
  std::cout << s->isPowerOfTwo(1) << std::endl;

  // test #2 - expecting a 0 - false
  std::cout << s->isPowerOfTwo(0) << std::endl;

  // test #3 - expecting a 0 - false
  std::cout << s->isPowerOfTwo(52) << std::endl;

  // test #4 - expecting a 1 - true
  std::cout << s->isPowerOfTwo(1024) << std::endl;


    return 0;
}