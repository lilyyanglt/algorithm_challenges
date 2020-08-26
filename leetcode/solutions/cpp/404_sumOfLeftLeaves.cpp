/* Link: https://leetcode.com/problems/reorder-list/
 * Problem #: 404
 * Author: lily yang
 * Date: Aug 24, 2020

 * Approach:
   Using top down recursive approach, I will pass information about the node itself in each recursive call whether each of the node is a right or left node. If it's a right node, then I will add 0 to the sum, if it's left node, then add the node->value to the sum.

   Time Complexity: O(n) - n being the total number of nodes since I'll be going through all the nodes
   Space Complexity: O(logn) on the callstack
 
*/ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumOfLeftLeaves(root, &sum, false);
        return sum;
    }
    
    void sumOfLeftLeaves(TreeNode* root, int* sum, bool isLeft) {
        if (!root) return;
        if (!root->left && !root->right) (isLeft) ? *sum += root->val : *sum += 0;
        sumOfLeftLeaves(root->left, sum, true);
        sumOfLeftLeaves(root->right, sum, false);
    }
};

int main() {

  // TO DO: need test case
}