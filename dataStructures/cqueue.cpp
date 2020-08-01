//Circular queue implementation
//last element will point to the first element

#include<iostream>
using namespace std;

//create node
class node{
    public:
    int data;
    node *next;
};

class cqueue{
    //create 2 nodes first and rear
    node *first, *rear;

    public:
    //initialize both to NULL
    cqueue(){
        first = rear = NULL;
    }

    //create a new node
    //check if both first and rear are NULL
    //if yes then update first and rear to the new node
    //else update rear to the new node and rear will point to the first node
    void push(int num){
        node *p = new node;
        p->data = num;
        if(first == NULL && rear == NULL){
            first = rear = p;
            first->next = p;
            rear->next = first;
        }else{
            rear->next = p;
            rear = p;
            rear->next = first;
        }
    }

    //chcek if first is NULL
    //if yes then the list is empty
    //else data of the first node will be stored and update first to the next node and delete the node and return data
    int pop(){
        node *p = first;
        if(p == NULL){
            cout<<"\nEmpty list";
            exit(0);
        }else{
            int x = p->data;
            first = first->next;
            delete p;
            return x;
        }
    }

    //search for an element in the list
    bool search(int num){
        node *p = first;
        if(p == NULL){
            return false;
        }else{
            do{
                if(p->data == num){
                    return true;
                }
                p = p->next;
            }while(p != first);
            return false;
        }
    }

    //display the list
    void disp(){
        node *p = first;
        if(p == NULL){
            cout<<"\nEmpty list";
            return;
        }else{
            do{
                cout<<p->data<<" ";
                p = p->next;
            }while(p != first);
        }
    }
};


int main(){
    int num, choice;
    cqueue cq;

    do{
        cout<<"\n1.Enter 1 to insert an element";
        cout<<"\n2.Enter 2 to delete an element";
        cout<<"\n3.Enter 3 to display the list";
        cout<<"\n4.Enter 4 to search an element";
        cout<<"\n0.Enter 0 to exit";
        cout<<"\n\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"\nEnter a number:";
                cin>>num;
                cq.push(num);
                break;
            }

            case 2:{
                cout<<"\nElement popped is:"<<cq.pop();
                break;
            }

            case 3:{
                cq.disp();
                break;
            }

            case 4:{
                cout<<"\nEnter number:";
                cin>>num;
                if(cq.search(num))
                    cout<<"\nElement found";
                else
                    cout<<"\nElement not found";
                break;
            }

            case 0:{
                break;
            }

            default:{
                cout<<"\nWrong choice";
            }
        }
    }while(choice != 0);

    return 0;
}