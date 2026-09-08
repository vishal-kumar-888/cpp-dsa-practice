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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1)
            return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        // Check whether k nodes exist
        ListNode* check = head;

        for (int i = 0; i < k; i++) {
            if (check == NULL)
                return head;

            check = check->next;
        }

        // Reverse first k nodes
        ListNode* next = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // head is now the last node of reversed group
        // curr points to the beginning of remaining list
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
