/*
Code to create a Binary Tree which has only 2 child nodes
*/
#include<bits/stdc++.h>
using namespace std;

//node class which has attributes data(int), left and right node
class node{
    public:
    int data;
    node *left, *right;
};

//binary tree class
class binTree{
    public:
    //creating a root node
    node *root;

    //initializing the root node to NULL
    binTree(){
        root = NULL;
    }

    /*
    searching the parent whose child nodes are to be added
    parameters are the root node and the value of the parent node
    initialize a new node to the root node
    if the data of the root node is the value of parent data, then we just return the new node which was initialized to the root node
    else we will recursively check the left sub tree, if we get the value, we just return the node
    else we will recursivwly check the right sub tree, if we get the value, we just return the node
    */
    node* searchParent(node *curr, int parent){
        node *p = curr;
        if(p->data == parent){
            return p;
        }
        
        //checking the left sub tree
        p = searchParent(curr->left, parent);
        //if we get the node we just return it
        if(p != NULL){
            return p;
        }

        //checking the right sub tree
        p = searchParent(curr->right, parent);
        //if we get the value, we just return the node
        if(p != NULL){
            return p;
        }

        //return NULL is we don't get it
        return NULL;
    }

    /*
    insert a node to the tree
    first create a new node and put data in it and initilize left and right pointers to NULL
    if root node is NULL, the new node is the root node
    else we search for parent 
    if we get it, we check if we want to insert the left or right node and also checks if the node is empty or nor
    if we want to insert the left or right, we just insert it in the left or right pointer otherwise the right pointer
    */
    void insert(int num, int parentValue, char dir){
        node *p = new node;
        p->data = num;
        p->left = NULL;
        p->right = NULL;
        if(root == NULL){
            root = p;
        }
        
        node *parent = searchParent(root, parentValue);
        
        if(parent == NULL){
            cout<<"\nParent not found";
            return;
        }else{
            if(dir == 'L' || dir == 'l'){
                if(parent->left == NULL){
                    parent->left = p;
                }else{
                    cout<<"\nNode is not empty";
                    return;
                }
            }else if(dir == 'r' || dir == 'R'){
                if(parent->right == NULL){
                    parent->right = p;
                }else{
                    cout<<"\nNode is not empty";
                    return; 
                }
            }
        }
    }

    //inorder traversal involves left node -> root -> right node
    void inorder(node *root){
        if(root == NULL){
            return;
        }else{
            inorder(root->left);
            cout<<" "<<root->data<<" ";
            inorder(root->right);
        }
    }

    //preorder traversal involves root -> left node -> right node
    void preorder(node *root){
        if(root == NULL){
            return;
        }else{
            cout<<" "<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    //postorder traversal involves left node -> right node -> root
    void postorder(node *root){
        if(root == NULL){
            return;
        }else{
            preorder(root->left);
            preorder(root->right);
            cout<<" "<<root->data<<" ";
        }
    }

    //calculating the height of the tree
    int height(node *root){
        //if there is no element in the tree, just return -1
        if(root == NULL)
            return -1;
        
        //calculate the height of the left subtree
        int leftHeight = height(root->left)+1;

        //claculate the height of the right subtree 
        int rightHeight = height(root->right)+1;

        //whichever height is greater, return that
        if(leftHeight > rightHeight)
            return leftHeight;
        return rightHeight;
    }
};


int main(){
    binTree bt;
    int num, choice, parent;
    char dir;

    do{
        cout<<"\n0.Enter 0 to exit";
        cout<<"\n1.Enter 1 to insert an element";
        cout<<"\n2.Enter 2 for inorder traversal";
        cout<<"\n3.Enter 3 for preorder traversal";
        cout<<"\n4.Enter 4 for postorder traversal";
        cout<<"\n5.Enter 5 to find the height of the tree";
        cout<<"\n\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"\nEnter number:";
                cin>>num;
                cout<<"\nEnter parent value:";
                cin>>parent;
                cout<<"\nEnter direction of the node:";
                cin>>dir;
                bt.insert(num,parent,dir);
                break;
            }
            case 2:{
                bt.inorder(bt.root);
                break;
            }
            case 3:{
                bt.preorder(bt.root);
                break;
            }
            case 4:{
                bt.postorder(bt.root);
                break;
            }
            case 5:{
                cout<<bt.height(bt.root);
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout<<"\nWrong choice!!!!";
            }
        }
    }while(choice != 0);
    return 0;
}