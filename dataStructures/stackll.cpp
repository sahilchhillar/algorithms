//This code is to generate a stack using a linked list and insert the elements at the end of the list

//Time complexity of insertion is O(1)
//Time complexity of deletion is O(n)
//Time complexity of searching is O(n)
//Space complexity is linear space

#include<bits/stdc++.h>
using namespace std;

//create a node class
class node{
    public:
    int data;
    node *next;
};

class stackll{
    //create a top pointer
    node *top;

    public:
    //initialize the top pointer to NULL
    stackll(){
        top = NULL;
    }

    //insert the element on the top of the stack and update the top pointer
    void push(int num){
        node *p = new node;
        p->data = num;
        p->next = top;
        top = p;
    }

    //delete the elements from the top of the stack
    //if the top pointer is NULL
    //returns nothing because stack is empty
    //else update the top pointer to the previous value and save the current value
    //delete the node and return the current value
    int pop(){
        if(top == NULL){
            cout<<"\nEmpty Stack";
            exit(0);
        }
        node *temp = top;
		top = top->next;
		
		int x = temp->data;
		delete temp;
		return x;
    }

    //searching n element in the list
    bool search(int num){
        node *p = top;
        while(p != NULL){
            if(p->data == num)
                return true;
        }
        return false;
    }

    //display the elements of the stack
    void disp(){
        node *p = top;
        while(p != NULL){
            cout<<p->data<<" ";
            p = p->next;
        }
    }

    //deallocates the memeory occupied by the object
    ~stackll(){
        cout<<"\nMemory released";
    }
};


int main(){
    int num, choice;

    stackll st;

    do{
        cout<<"\n1.Enter 1 to insert an element.";
        cout<<"\n2.Enter 2 to pop an element.";
        cout<<"\n3.Enter 3 to display the stack.";
        cout<<"\n4.Enter 4 to search an element in the stack.";
        cout<<"\n0.Enter 0 to exit";
        cout<<"\n\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"\nEnter the element:";
                cin>>num;
                st.push(num);
                break;
            }

            case 2:{
                cout<<st.pop();
                break;
            }

            case 3:{
                cout<<"\nStack is:\n";
                st.disp();
                break;
            }

            case 4:{
                cout<<"\nEnter the element:";
                cin>>num;

                if(st.search(num))
                    cout<<"\nElement found";
                else
                    cout<<"\nElement not found";
                break;
            }

            case 0:{
                break;
            }

            default:{
                cout<<"\nWrong choice!!!";
            }
        }
    } while (choice != 0);
    
    return 0;
}