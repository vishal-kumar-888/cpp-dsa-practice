// Problem: Delete Node in a Linked List
// LeetCode: 237
// Topic: Linked List
// Time Complexity: O(1)
// Space Complexity: O(1)

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int data){
        data = data;
        next = NULL;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* temp = node->next;

        node->val = temp->val;
        node->next = temp->next;

        delete temp;
    }
};