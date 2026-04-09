/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void Nodes(TreeNode* root,int &cnt) {
        if(!root) return;
        Nodes(root->left,cnt);
        cnt++;
        Nodes(root->right,cnt);
    }

    int countNodes(TreeNode* root) {
        int cnt =0;
        Nodes(root,cnt);
       return cnt;
    }
};
