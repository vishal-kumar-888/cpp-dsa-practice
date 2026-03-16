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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. Find length and tail
        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // 2. Make it circular
        tail->next = head;

        // 3. Find the new break point
        k = k % len;
        int stepsToNewTail = len - k;
        
        for (int i = 0; i < stepsToNewTail; i++) {
            tail = tail->next;
        }

        // 4. Set new head and break the circle
        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};
