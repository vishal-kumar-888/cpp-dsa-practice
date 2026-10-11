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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        //map each col no to its level and value of node 
        map<int , vector<pair<int ,int > > > mp;

        //queue stores nodes along with their col no and level
        queue<tuple <TreeNode* , int ,int> > q;

        //push root node to the queue
        q.push({root,0,0});

        while(!q.empty()){
            //access the front node 
            auto[curr, level,col]=q.front();
            q.pop();
            //map the node and its level to the col
            mp[col].push_back({level,curr->val});
            if(curr->left!=NULL){
                q.push({curr->left,level+1,col-1});
            }
            if(curr->right!=NULL){
                q.push({curr->right,level+1,col+1});
            }

        }
        vector<vector<int> > levels;
        for(auto &p : mp){
            //to sort the values having same col no
            sort(p.second.begin(),p.second.end());
            vector<int> ans;
            for(auto &a : p.second){
                
                ans.push_back(a.second);

            }
            levels.push_back(ans);
        }
        return levels;
    }
};
