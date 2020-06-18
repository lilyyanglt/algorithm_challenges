// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Problem #: 122
// Author: Lily Yang
// Date: June 18, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/122.md

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size(), max_profit = 0, difference = 0;
        
        if (n == 1) return 0;
        
       for (int i=0;i<n-1;i++) {
            if (prices[i+1] > prices[i]) {
                difference = prices[i+1] - prices[i];
                max_profit += difference;
            }
        }
        
        return max_profit;
        
    }
};

int main(void) {

  std::vector<int> prices1 = {3};
  std::vector<int> prices2 = {1, 1, 1, 1, 1};
  std::vector<int> prices3 = {7, 5, 4, 3, 2, 1};
  std::vector<int> prices4 = {1, 7, 8, 2, 3, 5};

  Solution *s = new Solution();

  // test case #1 - expecting a return of zero
  std::cout << s->maxProfit(prices1) << std::endl;

  // test case #2 - expecting a return of zero
   std::cout << s->maxProfit(prices2) << std::endl;

  // test case #3 - expecting a return of zero
   std::cout << s->maxProfit(prices3) << std::endl;

  // test case #4 - expecting a return of 10
   std::cout << s->maxProfit(prices4) << std::endl;

  return 0;

}