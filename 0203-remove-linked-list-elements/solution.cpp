/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Handle cases where head itself needs to be removed
    while (head != nullptr && head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    // If list is empty after removing head nodes
    if (head == nullptr) {
        return nullptr;
    }
    
    // Remove nodes from the rest of the list
    ListNode* current = head;
    while (current->next != nullptr) {
        if (current->next->val == val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            // Don't move current - next node might also need deletion
        } else {
            current = current->next;
        }
    }
    
    return head;
    }
};
