//program to implement circular queue using array
//front and rear are connected

//Time complexity of insertion and deletion is O(1)
//Space complexity is linear space

#include<iostream>
using namespace std;

class CQueue{
    int *circularQueue, front, rear, size;
    
    public:
    //initialize the size of the array and front and rear to -1
    CQueue(int size){
        this->size = size;
        front = rear = -1;
        circularQueue = new int[size];
    }

    //if front and rear both are -1 which means that the queue is empty
    //so change front and rear to 0 and insert the element
    //else check if the queue is full or not
    //if not full then just add the element
    //else display that it is full
    void push(int num){
        if(front == -1 && rear == -1 && !isFull()){
            front = 0;
            circularQueue[++rear] = num;
        }else if(!isFull()){
            circularQueue[++rear] = num;
        }else{
            cout<<"\nQueue is full";
            return;
        }
    }

    //store the front element in a temporary variable and increment front
    //checks if the queue is empty or not
    //if empty; just display that it is empty and exit
    //else return the element
    int pop(){
        int temp = front;
        front++;
        
        if(!isEmpty()){
            return circularQueue[temp];
        }else{
            cout<<"\nQueue is empty";
            exit(0);
        }
    }

    //display the queue
    void disp(){
        int temp = front;
        while(temp <= rear){
            cout<<circularQueue[temp++];
        }
    }

    //check if the queue is full or not
    bool isFull(){
        if(front > rear || rear == size-1)
            return true;
        return false;
    }

    //check if the queue is empty or not
    bool isEmpty(){
        if(front > rear)
            return true;
        return false;
    }

    //release the memory occupied by the object
    ~CQueue(){
        cout<<"\nMemory released";
    }
};


int main(){
    int num, choice, size;
    cout<<"\nEnter the size of the queue:";
    cin>>size;

    CQueue cqu(size);

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
                cqu.push(num);
                break;
            }

            case 2:{
                cout<<"\nElement popped is:"<<cqu.pop();
                break;
            }

            case 3:{
                cout<<"\nElements of the queue are:";
                cqu.disp();
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