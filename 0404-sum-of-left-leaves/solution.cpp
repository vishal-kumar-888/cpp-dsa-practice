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
    /*
     void calculateSum(TreeNode* root, int& sum, bool isLeft) {
     if (root == nullptr) return;

     // If it's a leaf node and it's a left child
     if (root->left == nullptr && root->right == nullptr && isLeft) {
         sum += root->val;
     }

     // Recurse left (true) and right (false)
     calculateSum(root->left, sum, true);
     calculateSum(root->right, sum, false);
 }
     int sumOfLeftLeaves(TreeNode* root) {
         int sum = 0;
         calculateSum(root,sum,false);
         return sum;
     } */

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int sum = 0;

        // Check if left child is a leaf
        if (root->left != nullptr && root->left->left == nullptr &&
            root->left->right == nullptr) {
            sum += root->left->val;
        }

        // Recurse on both children
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
