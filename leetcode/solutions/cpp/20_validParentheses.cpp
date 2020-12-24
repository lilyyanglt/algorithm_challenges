/* Link: https://leetcode.com/problems/valid-parentheses/
 * Problem #: 20
 * Author: lily yang
 * Date: Aug 27, 2020

 * Approach:
   Using a hashtable to store key value pairs of a valid parenthesis, the key will be opening and value will be the closing bracket. 
   Then Using a stack, track the opening brackets as I go through the string. 
   The initial approach was using whether the stack was empty as an indication for my next action, but then, there was duplicated code, so I improved it to add all the opening brackets to the stack regardless of whether the stack was empty or not and if it's a closing bracket that's encountered, check if the stack is empty, if it's empty, return false, else, use the top of the stack as the key, and check whether the value of the key matches the current string element, if not, return false, if yes, pop the element.


 * Complexity Analysis:
   Runtime: O(n) - n is the length of the string
   Memory: O(n) - worst case is if the string is composed of all opening brackets so the stack will grow to the size of the length of the string at worst case


 * Retro:
   I didn't run through my initial code to account for all the different edge cases so that lead to some issues such as "(])", or "{()}" or ""
   so learnings from this is to always make sure to test edge cases and general cases against your algorithm before implementation.
*/ 

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>


// initial approach was not DRY, i was repeating code, so I improved it
bool isValidInitial(std::string s) {
       std::unordered_map<char, char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        
        std::stack<char> st;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                if(s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                    st.push(s[i]);
                } else return false;
            } else {
                if(m[st.top()] == s[i]) {
                    st.pop();
                } else if(s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                        st.push(s[i]);
                } else {
                    return false;
                }
                
            }
        }
        
        return st.empty();
}


bool isValidImproved(std::string s) {
       std::unordered_map<char, char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        
        std::stack<char> st;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                st.push(s[i]);
            } else {

              if(st.empty()) {
                  return false;
              } else {
                    if(m[st.top()] == s[i]) {
                        st.pop();
                    } else {
                        return false;
                    } 
              }
            
            }
        }
        
        return st.empty();
}


int main(void) {
  
  std::string test1 = ""; // empty string is balanced
  std::string test2 = "(){}[]"; // valid string 
  std::string test3 = "(((((((}))))))"; // invalid string
  std::string test4 = "{()}"; // valid
  std::string test5 = "]["; // invalid
  
   assert(isValidImproved(test1) == true);
  assert(isValidImproved(test2) == true);
  assert(isValidImproved(test3) == false);
  assert(isValidImproved(test4) == true);
  assert(isValidImproved(test5) == false);

  std::cout << "passed all tests!\n";

  return 0;
}