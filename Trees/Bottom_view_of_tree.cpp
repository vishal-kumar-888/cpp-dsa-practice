// Bottom View of Binary Tree
// Problem No: 22 on Striver's SDE Sheet

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:    
    vector<int> bottomView(Node* root) {
        vector<int> result;
        if (!root) return result;

        // Map to store the bottom node at each horizontal distance
        map<int, int> bottomNodeMap;
        // Queue for level order traversal (node, horizontal distance)
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            Node* currentNode = front.first;
            int hd = front.second;

            // Update the bottom node at the current horizontal distance
            bottomNodeMap[hd] = currentNode->data;

            // Recur for left and right subtrees with updated horizontal distances
            if (currentNode->left) {
                q.push({currentNode->left, hd - 1});
            }
            if (currentNode->right) {
                q.push({currentNode->right, hd + 1});
            }
        }

        // Collecting the bottom view from the map
        for (const auto& pair : bottomNodeMap) {
            result.push_back(pair.second);
        }

        return result;
    }

    // Broute force approach
    void bottomViewUtil(Node* root, int hd, map<int, int>& bottomNodeMap) {
        if (!root) return;
        // Update the bottom node at the current horizontal distance
        bottomNodeMap[hd] = root->data;
        // Recur for left and right subtrees with updated horizontal distances
        bottomViewUtil(root->left, hd - 1, bottomNodeMap);
        bottomViewUtil(root->right, hd + 1, bottomNodeMap);
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
    vector<int> bottomViewResult = solution.bottomView(root);

    cout << "Bottom View of the Binary Tree: ";
    for (int val : bottomViewResult) {
        cout << val << " ";
    }
    cout << endl;

    map<int, int> bottomNodeMap;
    solution.bottomViewUtil(root, 0, bottomNodeMap);
    cout << "Bottom View of the Binary Tree (Brute Force): ";
    for (const auto& pair : bottomNodeMap) {
        cout << pair.second << " ";
    }
    cout << endl;

    // Clean up memory (delete nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;


    return 0;
}   
