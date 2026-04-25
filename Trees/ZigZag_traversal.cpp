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
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                int index = leftToRight ? i : size - 1 - i; 
                level[index] = node->data;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){    
                    q.push(node->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
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
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    for(const auto& level : result){
        for(int val : level){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}