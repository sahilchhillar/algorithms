/*
Best Case- O(n)
Average Case- O(n^2)
Worst Case- O(n^2)
*/

#include<iostream>
#include<vector>
using namespace std;

/*
Bubble sort swaps every 2 consecutive numbers and insert the largest number to the end of the array
first loop goes through the complete array
second loop goes through the complete array - the numbers which are placed at the end because they are in the correct position and we don't have to change them
*/
void bubbleSort(vector<int> &arr){
    int temp;
    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr.size()-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//Display the vector
void disp(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}


/*
create a vector array
take input until the input is a digit else come out of the loop and perform bubble sort algorithm and display the vector
*/
int main(){
    char num;
    vector<int> arr;
    cout<<"\nEnter vector elements and input any character to stop\n";
    while(true){
        cout<<"\nEnter number:";
        cin>>num;
        if(isdigit(num)){
            arr.push_back(int(num)-48);
        }else if(isalpha(num)){
            break;
        }
    }

    if(arr.size() == 0){
        cout<<"\nEmpty vector";
        exit(0);
    }else{
        bubbleSort(arr);
        disp(arr);
    }

    return 0;
}