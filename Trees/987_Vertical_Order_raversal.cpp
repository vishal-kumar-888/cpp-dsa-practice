#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>  // Required for multiset
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
    vector<vector<int>> verticalTraversal(Node* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->data);
            if(node->left){
                q.push({node->left, {x - 1, y + 1}});
            }
            if(node->right){
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
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
    vector<vector<int>> ans = sol.verticalTraversal(root);
    for(auto col : ans){
        for(int x : col){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}