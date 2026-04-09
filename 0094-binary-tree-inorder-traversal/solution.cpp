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
   vector<int> inOrder(TreeNode* node, vector<int>& res) {
    if (node == nullptr) return res;   
    // Traverse the left subtree first
    inOrder(node->left, res);
    
    // Visit the current node
    res.push_back(node->val);
    
    // Traverse the right subtree last
    inOrder(node->right, res);
    return res;
}

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        return inOrder(root,ans);
    }
};
