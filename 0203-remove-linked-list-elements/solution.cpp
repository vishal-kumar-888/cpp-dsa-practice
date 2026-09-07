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
        if (head == NULL)
            return NULL;

        ListNode* current = head;
        ListNode* prev = NULL;

        while (current != NULL) {
            if (current->val == val) {
                // Save next node before deleting current
                ListNode* next = current->next;

                if (prev == NULL) {
                    // Removing head
                    head = next;
                } else {
                    // Skip current node
                    prev->next = next;
                }

                delete current;
                current = next;
            } else {
                prev = current;
                current = current->next;
            }
        }

        return head;
    }
};
