// Problem: Binary Tree Preorder Traversal
// LeetCode: 144
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
    void preorder(TreeNode* node, vector<int>& res) {
        if (!node) return;

        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};