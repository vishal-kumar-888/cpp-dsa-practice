// Right View of Binary Tree
// Problem no: 199 on LeetCode
// Tc: O(n) where n is the number of nodes in the tree
// Sc: O(w) where w is the maximum width of the tree

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(Node* root) {
        vector<int> result;
        if (!root) return result;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                Node* currentNode = q.front();
                q.pop();
                // Add the last node of each level to the result
                if (i == levelSize - 1) {
                    result.push_back(currentNode->data);
                }
                // Enqueue left and right children
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }
        }
        return result;
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution solution;
    vector<int> rightViewResult = solution.rightSideView(root);

    cout << "Right View of the Binary Tree: ";
    for (int val : rightViewResult) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}