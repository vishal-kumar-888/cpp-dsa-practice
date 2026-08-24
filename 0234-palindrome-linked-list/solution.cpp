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
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        int size =0;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
            size++;
        }
        int right = size-1;
        int left =0;
        while(left<right){
            if(ans[left]!=ans[right]) return false;
            left++;
            right--;
        }
       return true;
    }
};
