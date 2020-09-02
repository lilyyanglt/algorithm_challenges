/* Link: https://leetcode.com/problems/valid-anagram/
 * Author: lily yang
 * Date: Sept 1, 2020

 Confirm that valid anagrams are strings that have exactly the same letters, but different order
 Confirm with interviewer if you can assume that it's all lowercase letters or all lowercase and capital letter
 Start thinking about the various strings to test, edge cases...etc

 * Approach2:
   First approach uses a static array to store the frequency of the individual letters in the first array
   loop through the first array, get the index of the array by using the character and subtracting the ascii value 
   of 'a'. Increment the frequency array at such index
   loop through the second array, get the index the same way as the first array. But this time, check if frequency[index] is already zero ie the character in second array isn't in the first array or the frequency isn't the same, if so, return false, if not, decrement the frequency[index]
   return true in the end if it reached the end of the code without returning false
   
   Time complexity: O(n) - n is the size of the array
   Space: O(1) - static array is the same size but each time I am reserving an array of 26 elements regardless of the size of the strings

   Approach 2:
   Same as the first but uses hashtable to keep frequency of each letter.
   When looping through the second string, if hashtable[char] is not found in the hashtable, immediately return false, or else it'll be the same as the first approach in terms of decrementing and seeing if the value is already zero.

   Time Complexity: O(n)
   Space Complexity: O(u) - u is the number of unique characters in the string

*/ 

#include <iostream>
#include <string>
#include <unordered_map>

#define calIndex(c) (int)(c) - (int)('a')
typedef std::string ss;


// if I can assume that all string letters are going to be lowercase
bool isAnagram1(ss& s, ss& t) {
  // get size of both string
  int sl = s.size(), tl = t.size();
  if (sl != tl) return false;

  // keep track of frequency of letters appearing in a static array with 26 elements
  // initial it to zero. Each index contains the value of the number of times a letter appears
  int freq[26] = {0};
  int index = 0;

  for (char c : s) {
    index = calIndex(c);
    freq[index]++;
  }

  for (char c : t) {
    index = calIndex(c);
    if (freq[index] == 0) return false;
    else freq[index]--;
  }

  return true;

}

// if the letters in the strings includes unicode characters
// then use this function instead

bool isAnagram2(ss& s, ss& t) {
    int sl = s.size(), tl = t.size();
        
        if (sl != tl) return false;
        
        // if the string contains unicode letters, then use a hashmap and use char as key
        std::unordered_map<char, int> m;
        
        for (char c : s) {
            m[c] += 1; 
        }
        
        for (char c : t) {
            // check if key is present
           if (m.find(c) != m.end()) {
               // key is found the letter was in previous
               if (m[c] == 0) return false;
               else m[c] -= 1;
           } else {
               return false;
           }
        }
        
        return true;
}



int main(void) {

  // different lengths "a" and "ab" - invalid
  // same length "ab" and "ba" - valid
  // same length "cd" and "cb" - invalid

  ss a1 = "bc";
  ss b1 = "ab";

  ss a2 = "b";
  ss b2 = "ab";

  ss a3 = "bc";
  ss b3 = "cb";

  assert(isAnagram1(a1, b1) == false);
  assert(isAnagram1(a2, b2) == false);
  assert(isAnagram1(a3, b3) == true);

  assert(isAnagram2(a1, b1) == false);
  assert(isAnagram2(a2, b2) == false);
  assert(isAnagram2(a3, b3) == true);

  std::cout << "passed all tests\n";

  return 0;
}
