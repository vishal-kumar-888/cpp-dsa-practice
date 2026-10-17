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
    bool validate(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr)
            return true; // empty is valid

        if (root->val <= minVal || root->val >= maxVal)
            return false; // outside bounds

        bool leftOk = validate(root->left, minVal, root->val);
        bool rightOk = validate(root->right, root->val, maxVal);

        return leftOk && rightOk;
    }

    bool isValidBST(TreeNode* root) { return validate(root, LLONG_MIN, LLONG_MAX); }
};
