#include<vector>
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
    void solve(TreeNode* root, int target, vector<int>& path,
               vector<vector<int>>& ans) {
        if (root == nullptr)
            return;

        path.push_back(root->val); // choose
        target -= root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (target == 0) {
                ans.push_back(path); // record a valid path
            }
        }

        solve(root->left, target, path, ans);
        solve(root->right, target, path, ans);

        path.pop_back(); // ← UNDO (backtrack)
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<int> path;
         vector<vector<int>> ans;
         solve(root,targetSum,path,ans);
         return ans;
    }
};
