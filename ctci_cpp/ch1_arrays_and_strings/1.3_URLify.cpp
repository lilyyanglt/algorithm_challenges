/* ***************************************************
* Cracking the Coding Interview
* 1.3 Write a method to replace all spaces in a string
* with '%20', we may assume that there's sufficient
* space at the end to hold the additional characters,
* and that you are given true lengths of the string. 
* Operation is to be performed in place

* Questions for Interviewer:
  1. Are there any other restrictions? Can I use additional
  memory to solve this?

* Approach 1: trim leading and ending white spaces
  then, loop through the string, if s[i] == " ", then add 
  "%20" to the auxillary string

  - Runtime: O(n*(2+a+b)) a is the size of the whitespace string
    b is the size of the alphabet string, these are all constants
    so the total runtime in the worst case is O(n)

* Approach 2: 

***************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <cstddef> // std::size_t
#include <unordered_map>

// approach 1
std::string urlify(std::string s, int length) {
  if (length == 0) return s;

  std::string output;
  std::string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  std::string whitespaces(" \t\n\v\f\r");

  // trim end spaces
  std::size_t t = s.find_last_not_of(whitespaces);
  if (t != std::string::npos) {
    s.erase(t+1); // because t would be the last non-space character
  } else {
    s.clear(); // if the first non-space character is the end of the string, then we know the whole string is empty
  }

  // trim beginning spaces
  t = s.find_first_of(alphabet);
  if (t != std::string::npos) {
    s.erase(0, t);
  }

  // create an auxillary string
  for (int i = 0; i<s.size(); i++) {
    if (s[i] == ' ') {
      output += "%20";
    } else {
      output += s[i];
    }
  }

  return output;
}

// testing the solution
int main(void) {
  
  // test case 1

  std::string test_s1 ("    Mr John Smith         ");
  int length = 13;
  std::string expected ("Mr%20John%20Smith");
  std::string actual = urlify(test_s1, length);
  std::cout << actual << std::endl;
  assert(actual.compare(expected) == 0);


  std::cout << "passed all test cases\n";

  return 0;
}