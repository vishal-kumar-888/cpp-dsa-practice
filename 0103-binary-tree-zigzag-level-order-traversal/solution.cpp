class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans; // Fixed: added missing '>'
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true; // Flag to track the direction

        while (!q.empty()) { // Fixed: condition must be !q.empty()
            int size = q.size();
            vector<int> levels;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop(); // Fixed: missing q.pop()

                levels.push_back(
                    node->val); // Fixed: missing node value insertion

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // If the direction is right-to-left, reverse the current level
            if (!leftToRight) {
                reverse(levels.begin(), levels.end());
            }

            ans.push_back(levels);
            leftToRight = !leftToRight; // Flip the flag for the next level
        }

        return ans;
    }
};

