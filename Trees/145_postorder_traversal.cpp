// Problem: Binary Tree Postorder Traversal
// LeetCode: 145
// Topic: Trees (DFS)
// Time Complexity: O(n)
// Space Complexity: O(h)

#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    // Helper function for postorder traversal
    void postOrder(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;

        postOrder(node->left, res);   // Left
        postOrder(node->right, res);  // Right
        res.push_back(node->val);     // Root
    }

    // Main function
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};