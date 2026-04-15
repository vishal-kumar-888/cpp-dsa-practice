// 110. Balanced Binary Tree
// Problem: Balanced Binary Tree
// LeetCode: 110
// Topic: Trees (DFS)
// Time Complexity: O(n)
// Space Complexity: O(h)

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int checkBalance(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = checkBalance(root->left);
        if (leftHeight == -1) return -1; // Left subtree is not balanced
        int rightHeight = checkBalance(root->right);
        if (rightHeight == -1) return -1; // Right subtree is not balanced
        if (abs(leftHeight - rightHeight) > 1) return -1; // Current node is not balanced
        return max(leftHeight, rightHeight) + 1; // Return the height of the current node
    }

    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
};