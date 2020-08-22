/* Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
   Problem #: 104
   Author: Lily Yang (for only the iterative solution)
   Date: Aug 11, 2020
   Notes: (https://github.com/lilyyanglt/algorithm_challenges/leetcode/blob/master/notes/104.md)

   Disclaimer: Recursive solutions are from Leetcode learnings

*/

#include <iostream>
#include <queue>
#include "./src/TreeNode.h"

// HELPER FUNCTION TO CHECK IF TREENODE IS WORKING
void printUsingBFS(TreeNode *& root) {
  if (root == nullptr) return;

  std::queue<TreeNode*> q;
  q.push(root);
  
  while(!q.empty()) {
    TreeNode *current = q.front();
    std::cout << current->data << " -> ";
    if(current->left != nullptr) q.push(current->left);
    if(current->right != nullptr) q.push(current->right);
    q.pop();
    delete current;
  }

  std::cout << '\n';

}

// this is the top-down approach to recursion 
// using a parameter to help the node determine its value and then pass it down to children nodes

void maxDepthRecursiveTopDown(TreeNode* root, int* answer, int depth = 1) {
  if (!root) return;

  // if left node and right nodes are empty
  if(!root->left && !root->right) {
    *answer = std::max(*answer, depth);
  }

  maxDepthRecursiveTopDown(root->left, answer, depth+1);
  maxDepthRecursiveTopDown(root->right, answer, depth+1);

}

int maxDepthRecursiveTopDown(TreeNode* root) {
  
  int answer = 0;
  maxDepthRecursiveTopDown(root, &answer);

  return answer;
}


// this is a bottom-up approach of recursion
int maxDepthRecursiveBottomUp(TreeNode * root) {

  if(root == nullptr) return 0;

  int leftHeight = maxDepthRecursiveBottomUp(root->left);
  int rightHeight = maxDepthRecursiveBottomUp(root->right);

  return std::max(leftHeight, rightHeight) + 1;

}

int maxDepthIterative(TreeNode *& root) {
   if (root == nullptr) return 0;
        
        // increment the height using BFS (iterative approach)
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        int nodeCount = 0, height = 0;
        
        while (true) {
            if (q.empty()) {
                break;
            } else {
                height++;
                
                nodeCount = q.size();
                
                // loop through the number of nodes and with each node, add the children to the queue
                while (nodeCount > 0) {
                    TreeNode* current = q.front();
                    if (current->left != nullptr) q.push(current->left);
                    if (current->right != nullptr) q.push(current->right);
                    // then remove the node from queue once it's added
                    q.pop();
                    nodeCount--;
                }
                 
            } // by end of this loop, we should have a queue with nodes from the level
            
        }
      return height;  
  }

int main(void) {
  
  // create binary tree based on leetcode input
  /*   [3] 
    [9]  [20]
        [15][7]  
  */
  TreeNode *root = new TreeNode(3);

  TreeNode *left = new TreeNode(9);
  TreeNode *right = new TreeNode(20);
  TreeNode *rightLeft = new TreeNode(15);
  TreeNode *rightRight = new TreeNode(7);
  root->left = left;
  root->right = right;
  root->right->right = rightRight;
  root->right->left = rightLeft;
  

  // test recursive - should print 3
  assert(maxDepthRecursiveBottomUp(root) == 3);

  // test recursive top down
  assert(maxDepthRecursiveTopDown(root) == 3);

  // test iterative - should print 3
  assert(maxDepthIterative(root) == 3); 

  std::cout << "passed all test cases\n" << std::endl;

  printUsingBFS(root);

  return 0;
}

