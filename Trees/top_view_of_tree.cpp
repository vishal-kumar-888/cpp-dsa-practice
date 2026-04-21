// Top View_of_Binary_Tree
// C++ program to print top view of binary tree
// Tc: O(n) where n is the number of nodes in the tree
// Sc: O(w) where w is the maximum width of the tree

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
    vector<int> topView(Node* root) {
        vector<int> result;
        if (!root) return result;
        map<int, int> topNodeMap; // Map to store the top node at each horizontal distance
        queue<pair<Node*, int>> q; // Queue to perform level order traversal
        q.push({root, 0}); // Start with the root node at horizontal distance 0
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            Node* currentNode = current.first;
            int hd = current.second; // Horizontal distance of the current node
            // If this is the first node at its horizontal distance, add it to the map
            if (topNodeMap.find(hd) == topNodeMap.end()) {
                topNodeMap[hd] = currentNode->data;
            }
            // Enqueue left and right children with their corresponding horizontal distances
            if (currentNode->left) {
                q.push({currentNode->left, hd - 1});
            }
            if (currentNode->right) {
                q.push({currentNode->right, hd + 1});
            }
        }   
        // Extract the top view nodes from the map and store them in the result vector
        for (const auto& pair : topNodeMap) {
            result.push_back(pair.second);
        }
        return result;
    }

    // Broute force approach
    void topViewUtil(Node* root, int hd, map<int, int>& topNodeMap) {
        if (!root) return;
        // If this is the first node at its horizontal distance, add it to the map
        if (topNodeMap.find(hd) == topNodeMap.end()) {
            topNodeMap[hd] = root->data;
        }
        // Recur for left and right subtrees with updated horizontal distances
        topViewUtil(root->left, hd - 1, topNodeMap);
        topViewUtil(root->right, hd + 1, topNodeMap);
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
    vector<int> topViewResult = solution.topView(root);

    cout << "Top View of the Binary Tree: ";
    for (int val : topViewResult) {
        cout << val << " ";
    }
    cout << endl;

    // Alternative approach using recursive method
    map<int, int> topNodeMap;
    solution.topViewUtil(root, 0, topNodeMap);
    cout << "Top View (Recursive): ";
    for (const auto& pair : topNodeMap) {
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