/* Link: https://leetcode.com/problems/reorder-list/
 * Problem #: 404
 * Author: lily yang
 * Date: Aug 23, 2020

 Approach 1:
 * Because this was a timed session, I wanted to get to the solution as quickly as possible, so I basically convered the 2D array into a 1D array, sorted it, and then performed binary search on it. 

 Time Complexity: Average case is Theta(n*m), n is the length of the 2D matrix, and m is the length of the individual array, but worst case is O(n^2) if n = m, but actually overall is n^2 + nlogn + logn
 Space Complexity: Average(n*m), and worst is also O(n^2) because I am creating a single array which is of length n*m and will be n*n if n = m.  
 
 */

#include <iostream>
#include <vector>

typedef std::vector<int> v;
typedef std::vector<std::vector<int>> vv;

 class Approach1 {
    public:
    bool solve(vv& matrix, int target) {
        v temp;
        int h = matrix.size(), w;
        
        // creates an array [1,3,9,2,5...]
        for (int i = 0; i < h; i++) {
            w = matrix[i].size();
            for (int j = 0; j < w; j++) {
                temp.push_back(matrix[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        return binarySearch(temp, 0, temp.size()-1, target);
    }
    
    bool binarySearch(v& arr, int start, int end, int target) {
        
        bool found = false;
        if (start > end) return found;
        
        int mid = start + ((end - start) / 2);
        if (arr[mid] == target) {
            found = true;
            return found;
            
        } else if (arr[mid] < target) {
            found = binarySearch(arr, mid + 1, end, target);
        } else {
            found = binarySearch(arr, start, end - 1, target);
        }
        
        return found;
    }
};

/* Approach 2:
   After learning my mistake in proceeding with the above approach which is highly ineffient, I had learned that because of the characteristics of the matrix (row - ascending order left to right, and column in ascending order down the column), I will start searching from the top right hand corner
   starting n = 0
   starting m = w - 1

   loop until n = h (height of matrix) and m = w (width of matrix):
   Then, if value is equal to matrix[n][m] return matrix[n][m]
   else if value is < matrix[n][m], decrease m
   else if value is > matrix[n][m], increase n

   Time Complexity: Average(h*w) h is the height of the matrix, and w is the size of each element, if h = w, then worst case is n^2, and that's it
   Space Complexity: O(1)
*/


class Approach2 {
    public:
    bool solve(vv& matrix, int target) {
        int h = matrix.size();
        int w = matrix[0].size(); // assuming each element is of equal length
        
        for (int n=0, m=w-1; n < h && m < w;) {
            if (matrix[n][m] == target) {
                return true;
            } else if (matrix[n][m] < target) {
                n++;
            } else {
                m--;
            } 
        }
        
        return false;
    }
};


int main() {

  Approach1 solve1;
  Approach2 solve2;

  vv matrix;
  v a = {1,3,5,7};
  v b = {10, 11, 16, 20};
  v c = {23, 30, 34, 50};

  matrix.push_back(a);
  matrix.push_back(b);
  matrix.push_back(c);

  assert(solve1.solve(matrix, 50) == true);

  assert(solve2.solve(matrix, 50) == true);

  assert(solve1.solve(matrix, 12) == false);

  assert(solve2.solve(matrix, 12) == false);

  std::cout << "Passed all tests" << std::endl;

  return 0;
}