#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};  

class Solution {
public: 
vector<int> boundary(Node* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }       
        // Add left boundary
        Node* current = root;
        while(current){
            if(current->left || current->right){
                ans.push_back(current->data);
            }
            if(current->left){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        // Add leaf nodes
        addLeaves(root, ans);
        // Add right boundary
        vector<int> rightBoundary;
        current = root->right;
        while(current){
            if(current->left || current->right){
                rightBoundary.push_back(current->data);
            }
            if(current->right){
                current = current->right;
            }
            else{   
                current = current->left;
            }
        }
        // Add right boundary in reverse order
        for(int i = rightBoundary.size() - 1; i >= 0; i--){
            ans.push_back(rightBoundary[i]);
        }
        return ans;
    }

    void addLeaves(Node* node, vector<int>& ans){
        if(node == NULL){
            return;
        }
        if(node->left == NULL && node->right == NULL){
            ans.push_back(node->data);
            return;
        }
        addLeaves(node->left, ans);
        addLeaves(node->right, ans);
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> ans = sol.boundary(root);
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}

