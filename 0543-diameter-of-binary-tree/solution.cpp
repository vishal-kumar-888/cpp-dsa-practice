/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int calculatediameter(TreeNode* root,int &dimeter){
        if(root == nullptr) return 0;
       int lh = calculatediameter(root->left,dimeter);
       int rh =calculatediameter(root->right,dimeter);
       dimeter = max(dimeter,rh+lh);
       return max(lh,rh)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dimeter =0;
        calculatediameter(root,dimeter);
        return dimeter;
        
    }
};
