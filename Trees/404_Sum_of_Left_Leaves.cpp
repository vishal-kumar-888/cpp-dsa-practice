// Problem: Sum of Left Leaves
// LeetCode: 404
// Topic: Trees (DFS)
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

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int result = s.sumOfLeftLeaves(root);
    cout << "Sum of left leaves: " << result << endl;

    return 0;
} 