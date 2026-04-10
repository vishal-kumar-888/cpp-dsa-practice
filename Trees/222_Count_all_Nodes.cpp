// problem: Count All Nodes in a Binary Tree
// Topic: Trees
// Time Complexity: O(n)
// Space Complexity: O(h)
#include<iostream>
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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return leftCount + rightCount + 1;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Total Nodes: " << s.countNodes(root) << endl; // Output: 5
    return 0;
}