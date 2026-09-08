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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        if(lists.size() == 1) return lists[0];
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < lists.size(); i++) {
           ListNode* head = lists[i];
           while(head != NULL){
           pq.push(head->val);
            head=head->next;
           }

        }
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while(!pq.empty()){
            head->next = new ListNode(pq.top());
            head = head->next;
            pq.pop();
        }
        return dummy->next;
    }
};
