/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         if (!root) return nullptr;
        
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr; // Tracks the previous node in the current level
           
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                // If there's a previous node in this level, connect it to the current one
                if (prev != nullptr) {
                    prev->next = node;
                }
                
                // Move the previous pointer to the current node
                prev = node;

                // Push children for the next level
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // The last node of the level explicitly points to NULL
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }
        
        return root;
    }
};
