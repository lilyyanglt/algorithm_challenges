/*
 January 2, 2021

 Approach:
 My initial approach was to create a new tree and using recursion, but came across some issues.


*/

#include <iostream>
#include "./src/TreeNode.h"


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        }
        
        if (t2 == NULL) {
            return t1;
        }
        
        // by this point, we know for sure t1 and t2 are not NULL and instead of 
        // creating a brand new tree
        // you can just use either t1 or t2 and update the val of the existing tree
        t2->data = t2->data + t1->data;
        t2->left = mergeTrees(t1->left, t2->left);
        t2->right = mergeTrees(t1->right, t2->right);
        
        return t2;

    }
    
};

// NEED TO FINISH THE TEST CASE
TreeNode * createTree(int * arr, int size) {
  
  TreeNode * root = new TreeNode(arr[0]);

  for (int i = 1; i < size-1; i++) {

    root->left = new TreeNode(arr[i]);
    root->right = new TreeNode(arr[i+1]);
  }

  return root;
}

int main() {

  int arr1[] = {1, 3, 2, 5};
  int arr2[] = {2, 1, 3, 0, 4, 0, 7};

  return 0;
}