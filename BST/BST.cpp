#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST{
    public:
    Node* root;

    BST(){
        root = NULL;
    }

    // Insert a new node with the given data into the BST
    void insert(int d){
        root = insert(root, d);
    }
    // Helper function to insert a new node into the BST recursively
    Node* insert(Node* node, int d){
        if(node == NULL){
            return new Node(d);
        }
        if(d < node->data){
            node->left = insert(node->left, d);
        }
        else if(d > node->data){
            node->right = insert(node->right, d);
        }
        return node;
    }

    void inorder(){
        inorder(root);
    }

    void inorder(Node* node){
        if(node == NULL){
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    //itrative insertion
    void insertIterative(int d){
        Node* newNode = new Node(d);
        if(root == NULL){
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = NULL;
        while(current != NULL){
            parent = current;
            if(d < current->data){
                current = current->left;
            }
            else if(d > current->data){
                current = current->right;
            }
            else{
                return; // Duplicate value, do not insert
            }
        }
        if(d < parent->data){   
            parent->left = newNode;
        }
        else{
            parent->right = newNode;
        }
    }   

    // Red Black Tree insertion in cpp

   // what is red black tree insertion in cpp?  

};

class RedBlackTree{
    // Red Black Tree implementation in C++
    Node* root;
    Node* TNULL;
    Node* pre;
};

int main(){
    BST bst;
    // bst.insert(5);
    // bst.insert(3);
    // bst.insert(7);
    // bst.insert(2);
    // bst.insert(4);
    // bst.insert(6);
    // bst.insert(8);
    bst.insertIterative(5);
    bst.insertIterative(3);
    bst.insertIterative(7);
    bst.insertIterative(2);
    bst.insertIterative(4);
    bst.insertIterative(1);
    bst.insertIterative(8);


    cout << "Inorder Traversal: ";
    bst.inorder();
    cout << endl;

    return 0;
}