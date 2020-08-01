/*
Best Case- O(n)
Average Case- O(n^2)
Worst Case- O(n^2)
*/

#include<iostream>
#include<vector>
using namespace std;

/*
Creates a partition of an array
Initially the first element is considered to be sorted and other to be unsorted
Counter points to the first element after the sorted section
Repeat until the unsorted section is completely traversed
    we select the first unsorted element
    swap other elements to the right to create the correct position and shift the unsorted element
    increment the counter by one
*/
void insertionSort(vector<int> &arr){
    int ele, j;
    for(int i=1;i<arr.size();i++){
        ele = arr[i];
        j = i-1;

        while(j >= 0 && ele < arr[j]){
            arr[j+1] = arr[j];
            j--;
            arr[j+1] = ele;
        }
    }
}

//Display the vector
void disp(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

/*
create a vector array
take input until the input is a digit else come out of the loop and perform bubble sort algorithm and display the vector
*/
int main(){
    char num;
    vector<int> arr;
    cout << "\nEnter vector elements and input any character to stop\n";
    while (true){
        cout << "\nEnter number:";
        cin >> num;
        if (isdigit(num)){
            arr.push_back(int(num) - 48);
        }
        else if (isalpha(num)){
            break;
        }
    }

    if (arr.size() == 0){
        cout << "\nEmpty vector";
        exit(0);
    }
    else{
        insertionSort(arr);
        disp(arr);
    }

    return 0;
}