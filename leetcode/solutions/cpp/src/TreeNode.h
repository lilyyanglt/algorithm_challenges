#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
  int data;
  TreeNode *left, *right;

  TreeNode(int d) : data(d), left(nullptr), right(nullptr) {} 
};

#endif //TREENODE_H