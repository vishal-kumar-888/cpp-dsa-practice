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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        // Map: HD → list of (level, value) pairs
        // Why pair? Because C++ sorts pairs by (first, then second)
        // automatically
        map<int, vector<pair<int, int>>> verticalNodes;

        // Queue holds: (node, horizontal distance, level)
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        // ---- BFS: collect all nodes with their (HD, level, value) ----
        while (!q.empty()) {
            auto [cur, hd, lvl] = q.front();
            q.pop();

            // Store (level, value) under this HD
            verticalNodes[hd].push_back({lvl, cur->val});

            if (cur->left)
                q.push({cur->left, hd - 1, lvl + 1});
            if (cur->right)
                q.push({cur->right, hd + 1, lvl + 1});
        }

        // ---- Post-process: sort each column, extract values ----
        for (auto& [hd, vec] : verticalNodes) { // auto& → modify in-place
            sort(vec.begin(), vec.end());       // sorts by level, then value

            vector<int> col;
            for (auto& [lvl, val] : vec) {
                col.push_back(val); // keep only value
            }
            ans.push_back(col);
        }

        return ans;
    }
};
