/*
Best Case- O(n^2)
Average Case- O(n^2)
Worst Case- O(n^2)
*/

#include<iostream>
#include<vector>
using namespace std;

/*
It considers 2 parts of an array one is sorted and the other one is unsorted array
Initially complete array is unsorted and it starts from the first element
it iterates over the array and find the smallest element and swaps it from the first element
Now the counter is incremented and the sorted part now has one element
It keep on going and finds smallest element in the unsorted array and then inserts it in the sorted part of the array
and so on
*/
void selectionSort(vector<int> &arr){
    int temp, minIndex;
    for(int i=0;i<arr.size();i++){
        minIndex = i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
        selectionSort(arr);
        disp(arr);
    }
    
    return 0;
}