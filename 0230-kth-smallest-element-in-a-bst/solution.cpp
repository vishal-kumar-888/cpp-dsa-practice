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
    int kthSmallest(TreeNode* root, int& k) {

        // 1. Do inorder traversal
        // 2. Keep track of count of nodes visited
        // 3. When count == k → return current node's value
        // 4. Otherwise continue
        if (root == NULL)
            return -1;

        int left = kthSmallest(root->left, k);
        if (left != -1)
            return left;

        k--;
        if (k == 0)
            return root->val;

        return kthSmallest(root->right, k);
    }
};
