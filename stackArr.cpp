// This code creates a stack of a particular size which is supplied by the user
// It pushes an element on the top of the stack because a stack uses LIFO(Last in first out) approach
// It pops an element from the top of the stack
// Stack is created using an array

//Time complexity of insertion and deletion is O(1)
//Time complexity of searching is O(n)
//Space complexity is linear space

#include<iostream>
using namespace std;

class Stack{
    int size, *stackArr, top;

    public:
    //create a stack of size 'n' and initialize top pointer to '-1'
    Stack(int size){
        this->size = size;
        stackArr = new int[size];
        top = -1;
    }

    //insert element to the top of the stack and also check if the stack is full or not
    void push(int num){
        if(!isFull()){
            stackArr[++top] = num;
        }else{
            cout<<"\nStack is Full";
            return;
        }
    }

    //remove the element from the stack and also check if the stack is empty    
    int pop(){
        if(!isEmpty()){
            return stackArr[top--];
        }else{
            cout<<"\nStack is empty";
            exit(0);
        }
    }

    //search an element in the stack
    bool search(int num){
        for(int i=top;i<=0;i--){
            if(stackArr[i] == num)
                return true;
        }
        return false;
    }

    //display the elements of the stack
    void disp(){
        for(int i=top;i>=0;i--){
            cout<<stackArr[i]<<" ";
        }
    }

    //check if the stack is full or not
    bool isFull(){
        if(top == size-1)
            return true;
        return false;
    }

    //check if the stack is empty or not
    bool isEmpty(){
        if(top == -1)
            return true;
        return false;
    }

    //deallocates the memory ocuupied by the object
    ~Stack(){
        delete[] stackArr;
    }
};



int main(){
    int num, choice, size;

    cout<<"\nEnter the size of the stack:";
    cin>>size;
    Stack st(size);

    do{
        cout<<"\n1.Enter 1 to insert an element.";
        cout<<"\n2.Enter 2 to pop an element.";
        cout<<"\n3.Enter 3 to display the stack.";
        cout<<"\n4.Enter 4 to search an element.";
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
                cout<<"\nElement popped is:"<<st.pop();
                break;
            }

            case 3:{
                cout<<"\nStack is:\n";
                st.disp();
                break;
            }

            case 4:{
                cout<<"\nEnter a number to be searched:";
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