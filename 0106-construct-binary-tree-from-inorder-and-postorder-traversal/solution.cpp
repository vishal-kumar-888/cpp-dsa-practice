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


TreeNode* build(vector<int>& inorder,
                vector<int>& postorder,
                int left,
                int right,int &postIndex) {

    if(left>right) return nullptr;

    int nodeVal = postorder[postIndex--];
    TreeNode* root = new TreeNode(nodeVal);
    int mid = left;
    while(inorder[mid]!=nodeVal) mid++;
    
    root->right = build(inorder,postorder,mid+1,right,postIndex);
    root->left = build(inorder,postorder,left,mid-1,postIndex);
    

    return root;
}
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
            int postIndex = po.size() - 1;
        return build(in,po,0, in.size()-1,postIndex);
    }
};
