/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        // If either subtree is already unbalanced
        if (left == -1 || right == -1) {
            return -1;
        }

        // Check current node
        if (abs(left - right) <= 1) {
            return max(left, right) + 1;
        }

        return -1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int ans = maxDepth(root);

        if (ans == -1)
            return false;

        return true;
    }
};
