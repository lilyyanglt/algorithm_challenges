/* ************************************************
* Cracking the Coding Interview
* 1.1 Is Unique: Implement an algorithm to 
* determine if a string has all unique characters
* What if you cannot use additional data structures

* Questions for Interview:
  - is the string sorted or can I assume it's not sorted?

* Approach 1: Brute Force
  If it's not sorted, I am going to sort the string first
  then loop through the string from i = 0 to n - 2, as soon
  as str[i] == str[i+1], return false, else return true

  - runtime: O(n log n) because of use of cpp sort function
  - space: O(1) did not use additional space

  If it's sorted already, then the approach is the same
  But runtime would be a little faster

  - runtime: O(n)

* Approach 2: Optimization

***************************************************/

#include <iostream>
#include <string>

// for a sorted string
bool solve(std::string str) {
  int n = str.size();

  if (n == 0) return false;

  for (int i=0; i<n-1; i++) {
    if (str[i] == str[i+1]) return false;
  }

  return true;
}

// for an unsorted string
bool solve2(std::string str) {
  sort(str.begin(), str.end());
  int n = str.size();

  if (n == 0) return false;
  for (int i=0; i<n-1; i++) {
    if (str[i] == str[i+1]) return false;
  }

  return true;

}

int main(void) {
  // test cases

  // when it's all unique - should return true
  std::string test_str1 = "abcdefghijklmnopq";
  assert(solve(test_str1) == true);
  
  // when it's not all unique - should return false
  std::string test_str2 = "abcdd";
  assert(solve(test_str2) == false);

  // when a string is empty == should return false
  std::string test_str3 = "";
  assert(solve(test_str3) == false);

  // when a string just has 1 character = should return true
  std::string test_str4 = "a";
  assert(solve(test_str4) == true);

  // when a string is unsorted = should return false
  std::string test_str5 = "zhinnp";
  assert(solve2(test_str5) == false);

  // when a string is unsorted = should return true
  std::string test_str6 = "zhnpq";
  assert(solve2(test_str6) == true);

  std::cout << "Passed all test cases\n";

  return 0;
}