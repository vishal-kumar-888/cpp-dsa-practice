// Problem: Reverse Linked List
// LeetCode: 206
// Topic: Linked List
// Time Complexity: O(n)
// Space Complexity: O(1)

struct ListNode{
    int data;
    ListNode* next;

    ListNode(int data) {
        data = data;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* forward = curr->next;

            curr->next = prev;

            prev = curr;

            curr = forward;
        }

        return prev;
    }
};