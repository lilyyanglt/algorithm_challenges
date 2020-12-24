/* Link: https://leetcode.com/problems/middle-of-the-linked-list/
* Problem #: 876
* Author: Lily Yang
* Date: June 26, 2020
* Notes: (https://github.com/lilyyanglt/leetcode/blob/master/notes/876.md)

Update on Aug 29, 2020

Approach:
- using slow and fast pointer for this question. 
- if the root is null, return - there's no middle
- if the root->next null - ie it only has 1 node, return node->val since that is the middle val
- else, A <- is the slow pointer, B <- fast pointer
- both starting at root 
- while B->next != null, I will assign A <- A->next, and B = B->next->next
  - if B is null, return A->val immediately

Time Complexity: O(n/2) - n is the number of nodes
Space: O(1) - the memory required does not grow with the input size

*/
#include <iostream>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
      
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution1 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr) {
            fast = fast->next;
            if (fast == nullptr) return slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};

// updated on Aug 29, 2020 - Updated solution
class Solution2 {
  public:
     int solve(LLNode* node) {
        // empty linkedlist
        if (!node) return -1;
        if (!node->next) return node->val;
        
        LLNode* A = node;
        LLNode* B = node;
        
        while (B->next!=nullptr) {
            A = A->next;
            B = B->next->next;
            if (B == nullptr) {
                return A->val;
            }
        }
        
        return A->val;
    }
};

// drives the program
int main(void) {
  
  // set up linked list - NEED TO SET THIS UP MORE ELEGANTLY
  ListNode *head = new ListNode(1);
  ListNode *temp = head;
  int count = 2;

  while (count < 5) {
    ListNode *node = new ListNode(count);
    temp->next = node;
    temp = node;
    count++;
  }

  // create solution

  Solution1 *s = new Solution1();

  // print out the middle pointer value
  // expect to print 3

  std::cout << s->middleNode(head)->val << std::endl;

  return 0;

}