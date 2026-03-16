// Problem: Rotate List
// LeetCode: 61
// Topic: Linked List
// Time Complexity: O(n)
// Space Complexity: O(1)
#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;

    ListNode(int data){
        data = data;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0)
            return head;

        ListNode* tail = head;
        int len = 1;

        while (tail->next) {
            tail = tail->next;
            len++;
        }

        tail->next = head;

        k = k % len;
        int stepsToNewTail = len - k;

        for (int i = 0; i < stepsToNewTail; i++) {
            tail = tail->next;
        }

        ListNode* newHead = tail->next;

        tail->next = nullptr;

        return newHead;
    }
};