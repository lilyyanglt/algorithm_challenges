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
  2. Need to confirm a few things about the input, is
  permutation case senstive? e.g. is God permutation of dog?
  3. Is "god     " different from dog
  4. 

* Approach 1: Sort the 2 strings and compare if they 
  are equal to each other

  - Runtime: O(n log n)
  - this algorithm is not optimal in some senses 

* Approach 2: Optimization - Count the # of times 
  character appears. The definition of permutation is
  that the 2 strings should have the same character 
  count.

* Hint #: 1, 84, 122, 131

***************************************************/

#include <iostream>
#include <string>

// Approach 1 - sort the strings
bool checkPermutation(std::string a, std::string b) {
  
  if (a.length() == 0 && b.length() == 0) return true;
  if (a.length() != b.length()) return false;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  return (a == b) ? true : false;
}

int main(void) {
  
  
  // APPROACH 1 TEST CASES
  // test #1

  std::string test_a1 = "abcd";
  std::string test_b1 = "bcad";
  assert(checkPermutation(test_a1, test_b1) == true);

  // test #2 

  std::string test_a2 = "abc";
  std::string test_b2 = "abcd";
  assert(checkPermutation(test_a2, test_b2) == false);

  // APPROACH 2 TEST CASES

  std::cout << "passed all test cases\n";

  return 0;
}
