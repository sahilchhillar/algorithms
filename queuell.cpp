//This code is to generate a queue using a linked list and insert the elements at the end of the list

//Time complexity of insertion is O(1)
//Time complexity of deletion is O(n)
//Space complexity is linear space

#include<bits/stdc++.h>
using namespace std;

//create a class node
class node{
    public:
    int data;
    node *next;
};

class queuell{
    //creating 2 node
    node *first, *rear;

    public:
    //initializing nodes to NULL
    queuell(){
        first = rear = NULL;
    }

    //first checks if the queue is empty
    //if yes then intitialize first to the new node
    //if no then change rear to that node
    void push(int num){
        node *p = new node;
        if(first == NULL && rear == NULL){
            first = p;
        }
        p->data = num;
        rear = p;
    }

    //delete the element from the starting position of the queue
    //if the queue is empty then returns nothing
    //else update first to the next value and return the value and delete the node
    int pop(){
        if(first == NULL || first > rear){
            cout<<"\nEmpty queue";
            exit(0);
        }
        node *temp = first;
        first = first->next;
        int x = temp->data;
        delete temp;
        return x;
    }

    //searching n element in the list
    bool search(int num){
        node *p = first;
        while(p != NULL){
            if(p->data == num)
                return true;
        }
        return false;
    }

    //display the queue elements
    void disp(){
        node *temp = first;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    //release the memory occupied by the object
    ~queuell(){
        cout<<"\nMemory released";
    }
};


int main(){
    int num, choice;

    queuell qu;

    do{
        cout<<"\n1.Enter 1 to insert an element in the queue.";
        cout<<"\n2.Enter 2 to delete an element in the queue.";
        cout<<"\n3.Enter 3 to display the queue.";
        cout<<"\n0.Enter 0 to exit.";
        cout<<"\n\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"\nEnter the number:";
                cin>>num;
                qu.push(num);
                break;
            }

            case 2:{
                cout<<"\nElement popped is:"<<qu.pop();
                break;
            }

            case 3:{
                cout<<"\nElements of the queue are:";
                qu.disp();
                break;
            }

            case 4:{
                cout<<"\nEnter the element:";
                cin>>num;

                if(qu.search(num))
                    cout<<"\nElement found";
                else
                    cout<<"\nElement not found";
                break;
            }

            case 0:{
                break;
            }

            default:{
                cout<<"\nWrong choice!!!!";
            }
        }
    } while (choice != 0);

    return 0;    
}