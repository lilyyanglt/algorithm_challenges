/* Link: https://leetcode.com/problems/pascals-triangle/ and https://leetcode.com/problems/pascals-triangle-ii/
   Problem #: 118 and 119
   Author: Lily Yang
   Date: Aug 12, 2020
   Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/118.md)

  Goal: in 118, it asking you to return a 2d array that's representing a pascal's triangle, then 119 is to built on that so 118 is the preamble to solving a dynamic programming problem in 119. Once you have the structure created, then returning the row at index k is going to be O(1).

  Time Complexity: 

*/

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> vv;

// question 118
vv generate(int numRows) {
  
  vv output;
  
    for (int i = 0; i < numRows; i++) {
        std::vector<int> row;
        
        if(i == 0) {
  
            row.push_back(1);
            output.push_back(row);
  
        } else {
            
            // because the number of elements in a row is i
            for (int j=0; j <= i; j++) {
                // first and last element is always 1
                if(j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    // get the previous row in the vector output
                    std::vector<int> prevRow = output[i-1];
                    // each value from n to n - 2 can be calculated from previous row
                    row.push_back(prevRow[j] + prevRow[j-1]);
                }
            }
            
            output.push_back(row);
            
        }
    }
    
    return output;
}


// question 119
std::vector<int> getRow(int rowIndex) {
  vv dp = generate(rowIndex + 1);

  return dp[rowIndex];
}


int main() {

  // test when numRows is 5
  /*
    [
      [1],
      [1,1],
      [1,2,1],
      [1,3,3,1],
      [1,4,6,4,1]
    ]
  */

  // test generate function

  int num = 5;

  vv result = generate(num);

  for (int i = 0; i < num; i++) {
    for (int j=0; j < result[i].size(); j++) {
      std::cout << ' ' << result[i][j];
    }
    std::cout << '\n' << std::endl;
  }

  // test getRow - should print 1 3 3 1
  std::cout << "testing getRow function: \n";
  std::vector<int> output = getRow(3);

  for (int i = 0; i<output.size(); i++) {
    std::cout << ' ' << output[i];
  }
  std::cout << std::endl;

  return 0;
}