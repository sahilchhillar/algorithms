//this program creates a linked list using naive method
//inserts data in the beginning, end or at some position in the linked list
//deletes data from the beginning, end or at some position in the linked list
//traverse the linked list and display the data of the linked list

//Time complexity of insertion and deletion O(n)
//Space complexity is linear space

#include<iostream>
using namespace std;

//create a node class
class node{
    public:
    int data;
    node *next;
};

class linkedList{
    //create 2 nodes to point to the beginning and end of the list
    node *first, *rear;

    public:
    //initialize both the pointers to NULL
    linkedList(){
        first = NULL;
        rear = NULL;
    }

    //first create a node and assign some data in it
    //checks if it is the first node to enter
    //if yes then both first and rear pointer will be that node
    //else new node is points to first and change the new node to first
    void pushFront(int num){
        node *p = new node;
        p->data = num;
        if(first == NULL && rear == NULL){
            first = rear = p;
            p->next = NULL;
        }else{
            p->next = first;
            first = p;
        }
    }

    //first creates a node and assign some value to it
    //checks if it is the first node to be created
    //if yes then both first and rear pointer will be that node
    //else rear will first point to the new node and change rear pointer to the new node
    void pushBack(int num){
        node *p = new node;
        p->data = num;
        if(first == NULL && rear == NULL){
            first = rear = p;
            rear->next = NULL;
        }else{
            rear->next = p;
            rear = p;
            rear->next = NULL;
        }

    }

    //first create a new node and assign some value to it
    //creates a position counter to check the position value
    //if the position is not a valid position then just print incorrct and return
    //else if the positon number is '0'(first position) then node points to the first node and first node is the new node
    //else create 2 new nodes and assign first and first->next to them
    //iterate till we find the position and insert the value there
    void pushAtPos(int num, int pos){
        node *p = new node;
        p->data = num;
        int count = 1;
        if(pos < 0){
            cout<<"\nPosition is not correct";
            return;
        }else if(pos == 0){
            p->next = first;
            first = p;
        }else{
            node *temp = first;
            node *temp2 = first->next;
            while(temp2 != NULL){
                if(count == pos){
                    temp->next = p;
                    p->next = temp2;
                    return;
                }
                count++;
                temp = temp->next;
                temp2 = temp2->next;
            }
            cout<<"\nPosition not found";
            return;
        }
    }

    //first check if first and rear is NULL that means that the list is empty
    //else if first is NULL; is yes then it displays node is NULL
    //if front is rear; it returns the data and assign NULL to first and rear
    //else just delete from front
    int popFront(){
        if(first == NULL && rear == NULL){
            cout<<"\nEmpty list";
            exit(0);
        }else if(first == NULL){
            node *temp = first;
            first = first->next;
            delete temp;
            cout<<"\nThis node was NULL";
            exit(0);
        }else if(first == rear){
            node *temp = first;
            int x = temp->data;
            first = NULL;
            rear = NULL;
            return x;
            delete temp;
        }else{
            node *temp = first;
            int x = temp->data;
            first = first->next;
            delete temp;
            return x;
        }
    }


    //first checks if first and rear are NULL; if yes then the list is empty
    //else checks if there is just one element in the list; if yes then assign NULL to first and rear
    //else delete from back
    int popBack(){
        if(first == NULL && rear == NULL){
            cout<<"\nEmpty list";
            exit(0);
        }else if(first == rear){
            node *temp = rear;
            int x = temp->data;
            delete temp;
            first = NULL;
            rear = NULL;
            return x;
        }else{
            node *temp1 = first;
            node *temp2 = first->next;
            int x;
            while(temp2 != NULL){
                if(temp2 == rear){
                    rear = temp1;
                    x = temp2->data;
                    rear->next = NULL;
                    break;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            delete temp2;
            return x;
        }
    }

    
    //first checks if both first and rear are NULL if yes then just display that list is empty
    //if pos == 0, delete first node
    //else if pos < 0, wrong position
    //else create 2 nodes, pointing to first and first->next and also a counter to check the position
    //loop until the next node is null
    //if counter is equal to position; then check if the node is the last node or not
    //if yes then just delete the rear node and change the rear node to the previous one
    //else delete the node and temp->next = temp2->next
    //the temp2 will point to NULL and we will delete it and return the value
    int popAtPos(int pos){
        if(first == NULL || rear == NULL){
            cout<<"\nEmpty linked list";
            exit(0);
        }else if(pos < 0){
            cout<<"\nWrong position";
            exit(0);
        }else if(pos == 0){
            node *temp = first;
            int x = temp->data;
            first = first->next;
            delete temp;
            return x;
        }else{
            node *temp1 = first;
            node *temp2 = first->next;
            int x, count=1;
            while(temp2 != NULL){
                if(count == pos){
                    if(temp2 != rear){
                        temp1->next = temp2->next;
                        temp2->next = NULL;
                        x = temp2->data;
                        delete temp2;
                        return x;
                    }else{
                        rear = temp1;
                        rear->next = NULL;
                        x = temp2->data;
                        delete temp2;
                        return x;
                    }
                }
                count++;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            cout<<"\nPosition not found";
            exit(0);
        }
    }

    //search an element in the list
    bool search(int num){
        node *p = first;
        while(p != NULL){
            if(p->data == num)
                return true;
        }
        return false;
    }

    //display the linked list
    void disp(){
        node *p = first;
        if(p == NULL){
            cout<<"\nNothing to display";
            return;
        }else{
            while(p != NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
        }
    }
};


int main(){
    int num, choice, pos;
    linkedList ll;
    do{
        cout<<"\n1.Enter 1 to insert the value at the front";
        cout<<"\n2.Enter 2 to insert the value in the back";
        cout<<"\n3.Enter 3 to insert the value at a particular position";
        cout<<"\n4.Enter 4 to delete the value fron front";
        cout<<"\n5.Enter 5 to delete the value from back";
        cout<<"\n6.Enter 6 to delete the value from a position";
        cout<<"\n7.Enter 7 to display the list";
        cout<<"\n8.Enter 8 to search an element";
        cout<<"\n0.Enter 0 to exit.";
        cout<<"\n\nEnter the choice:";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"\nEnter the number you want to insert:";
                cin>>num;
                ll.pushFront(num);
                break;
            }

            case 2:{
                cout<<"\nEnter the number you want to insert:";
                cin>>num;
                ll.pushBack(num);
                break;
            }

            case 3:{
                cout<<"\nEnter the number you want to insert:";
                cin>>num;
                cout<<"\nEnter the position:";
                cin>>pos;
                ll.pushAtPos(num, pos);
                break;
            }

            case 4:{
                cout<<"\nDeleted element is:"<<ll.popFront();
                break;
            }

            case 5:{
                cout<<"\nDeleted element is:"<<ll.popBack();
                break;
            }

            case 6:{
                cout<<"\nEntert the position:";
                cin>>pos;
                cout<<"\nDeleted element is:"<<ll.popAtPos(pos);
                break;
            }

            case 7:{
                ll.disp();
                break;
            }

            case 8:{
                cout<<"\nEnter the element:";
                cin>>num;

                if(ll.search(num))
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
    }while(choice != 0);

    return 0;
}