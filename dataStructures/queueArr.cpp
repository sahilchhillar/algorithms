// This code creates a queue of a particular size which is supplied by the user
// It pushes an element at the end of the queue because a queue uses FIFO(First in first out) approach
// It pops an element from the starting of the queue
// Stack is created using an array

//Time complexity of insertion and deletion is O(1)
//Time complexity of searching is O(n)
//Space complexity is linear space

#include<iostream>
using namespace std;

class Queue{
    int size, *queueArr, first, rear;

    public:
    //creates a queue of size 'n' and initialize rear and first to '-1'
    Queue(int size){
        this->size = size;
        queueArr = new int[size];
        first = rear = -1;
    }

    //insert an element in the queue and updates rear and also checks if the queue is full or not
    void push(int num){
        if(first == -1 && rear == -1){
            queueArr[++rear] = num;
            first = 0;
        }else if(!isFull()){
            queueArr[++rear] = num;
        }else{
            cout<<"\nQueue is Full!!!";
            return;
        }
    }

    //deletes an element from the starting of the queue and updates first and also checks if the queue is empty or not
    int pop(){
        int temp = first;
        first++;

        if(!isEmpty()){
            return queueArr[temp];
        }else{
            cout<<"\nQueue is empty";
            exit(0);
        }
    }

    //search an element in the queue
    bool search(int num){
        for(int i=first;i<=rear;i++){
            if(queueArr[i] == num)
                return true;
        }
        return false;
    }

    //displays the elements of the queue
    void disp(){
        for(int i=first;i<=rear;i++){
            cout<<queueArr[i]<<" ";
        }
    }

    //checks if the queue is full
    bool isFull(){
        if(rear == size)
            return true;
        return false;
    }

    //checks if the queue is empty
    bool isEmpty(){
        if(first > rear)
            return true;
        return false;
    }

    //deallocates the memory ocuupied by the object
    ~Queue(){
        delete[] queueArr;
    }
};


int main(){
    int num, choice, size;
    cout<<"\nEnter the size of the queue:";
    cin>>size;

    Queue qu(size);

    do{
        cout<<"\n1.Enter 1 to insert an element in the queue.";
        cout<<"\n2.Enter 2 to delete an element in the queue.";
        cout<<"\n3.Enter 3 to display the queue.";
        cout<<"\n4.Enter 4 to search an element.";
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