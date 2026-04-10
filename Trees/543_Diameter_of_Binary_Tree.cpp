// Problem: Diameter of Binary Tree
// LeetCode: 543
// Topic: Trees (DFS)
// Time Complexity: O(n)
// Space Complexity: O(h)

#include <iostream>
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

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int diameter = s.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    return 0;
}