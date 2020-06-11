// Link: https://leetcode.com/problems/coin-change-2/
// Source: Geeks for Geeks, Youtube
// Problem #: 518
// Author: Lily Yang
// Date: June 7, 8, 9, 2020
// Notes: (https://github.com/lilyyanglt/leetcode/blob/master/notes/518.md

#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        if (n == 0 && amount > 0) return 0;
        if (n == 0 && amount == 0) return 1;
        
        int i, j, x, y, newAmount;
        
        int table[amount + 1][n];
        
        // when amount is 0, any coin denomination will have 1 solution
        for (i = 0; i < n; i++)
            table[0][i] = 1;
        
        // now populating my 2d array with the rest of the values
        for (i = 1; i <= amount; i++ ) {
            for (j = 0; j < n; j++) {
                x = (j >= 1) ? table[i][j-1] : 0 ;
                
                newAmount = i - coins[j];
                y = (newAmount < 0) ? 0 : table[newAmount][j];
            
                table[i][j] = x + y;
            }
        }
        
        // once I have the table populated, I can search for it using indexes
        return table[amount][n-1];
}

// drives the program
int main(void) {
  
  vector<int> coins{1, 2, 5};
  
  int result = change(5, coins);

  cout << result << endl;

  return 0;
}