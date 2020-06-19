// Link: https://leetcode.com/problems/group-anagrams/
// Problem #: 49
// Author for Solution: Errichto (https://www.youtube.com/watch?v=U8glv4sX6Pw&t=4s)
// Author for rest of code: Lily Yang
// Date: June 19, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/49.md


#include <iostream>
#include <vector>
#include <unordered_map>

// defining alias for type to prevent having to write such long type definitions
typedef std::vector< std::vector<std::string> > vvs;
typedef std::vector<std::string> vs;
typedef std::unordered_map< std::string, std::vector<std::string> > um;

class Solution {
public:
    vvs groupAnagrams(vs& strs) {
        vvs output;
        um map;
        
        for(auto s : strs) {
            std::string copy = s;
            sort(copy.begin(), copy.end());

            // e.g if s = 'eat'
            // first entry of map: { 'aet': {'eat'} }
            map[copy].push_back(s);
        }
      
        for(auto wordVector : map) {
            output.push_back(wordVector.second);
        }
        
        return output;
    }
};

int main(void) {

  vs v = {"eat", "tea", "tan", "ate", "nat", "bat"};

  Solution *s = new Solution();

  vvs output = s->groupAnagrams(v);

  for (auto i : output) {
    for (auto j : i) {
      std::cout << j << ", ";
    }
    std::cout << std::endl;
  }

  return 0;
}