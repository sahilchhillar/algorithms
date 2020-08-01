//tree data structure
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;
};

class tree{
    
    public:
    //create root node
    node *root;

    //initialize the root node
    tree(){
        root = NULL;
    }

    //insert element in the tree
    void push(int num){
        node *p = new node;
        p->data = num;
        node *curr = root;
        node *parent = root;

        while(curr){
            parent = curr;
            if(curr->data < num){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }

        if(parent == NULL){
            root = p;
        }else{
            if(parent->data < num){
                parent->right = p;
            }else{
                parent->left = p;
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
};



int main(){
    int num, choice;
    tree t;
    do{
        cout<<"\n1.Enter 1 to insert an element in the tree";
        cout<<"\n2.Enter 2 to display inoder traversal of the tree";
        cout<<"\n3.Enter 3 to display preorder traversal of the tree";
        cout<<"\n4.Enter 4 to display postorder traversal of the tree";
        cout<<"\n0.Enter 0 to exit";
        cout<<"\n\nEnter the choice:";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"\nEnter the number:";
                cin>>num;
                t.push(num);
                break;
            }

            case 2:{
                cout<<"\nTree is:\n";
                t.inorder(t.root);
                break;
            }

            case 3:{
                cout<<"\nTree is:\n";
                t.preorder(t.root);
                break;
            }

            case 4:{
                cout<<"\nTree is:\n";
                t.postorder(t.root);
                break;
            }

            case 0:{
                break;
            }

            default:{
                cout<<"\nWrong input";
            }
        }
    }while(choice != 0);

    return 0;
}