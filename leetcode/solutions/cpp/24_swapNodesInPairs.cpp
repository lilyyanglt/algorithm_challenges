/* Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 * Problem #: 24
 * Author: lily yang
 * Date: Oct 11, 2020
 * 
 * Problem: You are given a linked list, and you are asked to swap 2 adjacent nodes and return its head. This is a recursive problem because the
 * smallest problem is just swapping 2 nodes and then the next operation is using the next next node.

 * Approach:
   Base case: if head is null or head->next is null (meaning only has 1 node) return head - nothing to swap
   Recursive case:
   if I have 2 nodes, node1 -> node2 -> null
   node2 will point to node1
   node1 will need to point to null
   swapPairs(null)

   head will need to be updated to point to node2

   I struggled a bit on how to implement this because I am not sure how to use the node returned by the recursive function, but then it hit me, node1 = swapPairs(null) - because node1 is pointing to the node that will be returned by the base case. This is always something I struggled with re how to use the information returned by the recursion.

   The second challenge I had was how to update the head? I know the head will now need to point to node2, so I can't change the head pointer, I then choose to make a copy of it in the function and used temp instead.

 * Complexity Analysis:
   Runtime: O(n/2) - n being the number of nodes, so recursive calls is being made on every 2 nodes so n/2 on average, but upperbound is n.
   Memory: O(n) - the callstack is goign to be occupied n/2 


 * Retro:
   Always consider the return value of the base case and use it in your recursive case because often times that's the most challenging part.
*/ 



#include <iostream>
#include "./src/ListNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (!head || !head->next) {
          return head;
        }
        
        ListNode* temp = head;
        ListNode* newHead = temp->next;
        ListNode* nextnext = temp->next->next;
        temp->next->next = temp;
        temp->next = swapPairs(nextnext);
        
        head = newHead;
        
        return head;
        
    }
};

int main() {

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
  
  // NEED TEST CASES


  return 0;

}

