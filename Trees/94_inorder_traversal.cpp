// Problem: Binary Tree Inorder Traversal
// LeetCode: 94
// Topic: Trees (DFS)
// Time Complexity: O(n)
// Space Complexity: O(h)

#include <vector>
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
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) return;

        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};