/* Link: https://leetcode.com/problems/reorder-list/
 * Problem #: 143
 * Author: lily yang
 * Date: Aug 20, 2020

 * Approach:
   Because there's no indexing and doubly linked list for this problem, each iteration I would have to traverse the linked list to find the second to last node.
   Get the tail node from the second to last node, update second to last node to point to null, first node in the list to point to tail and update tail->next to point to temp->next. The order of operation is important here as you don't want to loose any connection by accident before you track it. 

   For odd numbered nodes, the condition to check when the outer loop will stop if temp->next->next will fail because for ood number of nodes, we'll have temp be equaling to the second to last node, so we'll want to break out of the loop if this is the case.

 * Time Complexity: O(n^2) - because for each iteration, I am travering the lst from beginning to end and n being the
   number of nodes

   Space Complexity: O(1) - There's no additional space needed as input size increases, so it remains constant

 * Approach 2:
   The first approach is not optimized since it's running at O(n^2) so I should be able to improve on it.
*/ 

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
        
        ListNode* temp = head;
        ListNode* prev;
        ListNode* tail;
        
        while (temp->next->next != nullptr) {
            
            prev = temp;
            while(prev->next->next != nullptr) {
                prev = prev->next;
            }
            
            tail = prev->next;
            prev->next = nullptr;
            tail->next = temp->next;
            temp->next = tail;
            temp = tail->next;
            
            if (temp->next == nullptr) break;
        }
    }
};
