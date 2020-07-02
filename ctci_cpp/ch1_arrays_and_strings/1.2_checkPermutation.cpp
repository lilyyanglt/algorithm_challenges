/* ************************************************
* Cracking the Coding Interview
* 1.2 Check Permutation: Given 2 strings, write a method
* to decide if one is a permutation of the other

* Definition of Permutation: A string is a permutation 
  of another string if the string has the exact same 
  characters but order of characters can be different
  e.g. 'abcd' is a permutation of 'bcda'

* Questions for Interviewer:
  1. Can the original string be modified?
  ie. Can I use built in sort function? - Yes

* Approach 1: Sort the 2 strings and compare if they 
  are equal to each other

  - Runtime: O(n log n) due to using sort function

* Approach 2: Optimization - try to do O(n) time

  

***************************************************/

#include <iostream>
#include <string>

// Approach 1 -
bool checkPermutation(std::string a, std::string b) {
  
  if (a.size() == 0 && b.size() == 0) return true;
  if (a.size() != b.size()) return false;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  return (a == b) ? true : false;
}

int main(void) {
  
  // test case 1

  std::string test_a1 = "abcd";
  std::string test_b1 = "bcad";
  assert(checkPermutation(test_a1, test_b1) == true);

  // test case 2 

  std::string test_a2 = "abc";
  std::string test_b2 = "abcd";
  assert(checkPermutation(test_a2, test_b2) == false);


  std::cout << "passed all test cases\n";

  return 0;
}
