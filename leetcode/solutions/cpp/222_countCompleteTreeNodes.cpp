// Link: https://leetcode.com/problems/count-complete-tree-nodes/
// Problem #: 222
// Author: lily
// Date: June 23, 2020
// Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/222.md

#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
  public:
    int countNodes(TreeNode *root) {
      if (root == nullptr) return 0;

      return 1 + countNodes(root->right) + countNodes(root->left);
    }
};

int main(void) {
  
  TreeNode *root = new TreeNode();

  Solution *s = new Solution();

  // test #1 - expect return of 1;
  std::cout << s->countNodes(root) << std::endl;

  int nodes[] = {1, 2, 3};

  // NEED TO FIND HOW TO BUILD THIS TREE MORE ELEGANTLY 
  TreeNode *root2 = new TreeNode(nodes[0]);

  root2->left = new TreeNode(nodes[1]);

  root2->right = new TreeNode(nodes[2]);

  // test #2 - expect return of 3;
  std::cout << s->countNodes(root2) << std::endl;


  return 0;
}