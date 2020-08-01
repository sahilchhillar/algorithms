/*
Best Case- O(nlog(n))
Average Case- O(nlog(n))
Worst Case- O(n^2)
*/

#include<iostream>
#include<vector>
using namespace std;

/*
Initially the last element is the pivot element
We then arrange the array such that all the elements on the left of the pivot are smaller than the pivot and right ones are greater
The pivot element is placed in the correct position
*/
int partition(vector<int> &arr, int l, int h){
    int i = l-1, temp;
    int pivot = arr[h];
    for(int j=l;j<h;j++){
        if(arr[j] <= pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[h];
    arr[h] = temp;

    return (i+1);
}

/*
Find out the pivot element for the original array
Then we divide the array into 2 parts, smaller than pivot and greater than pivot
The sorting algorithm again finds the pivot in the subarrays and arranage the array
This is a recursive algorithm 
*/
void quickSort(vector<int> &arr, int l, int h){
    if(l < h){
        int pivot = partition(arr, l, h);
        quickSort(arr,l, pivot-1);
        quickSort(arr, pivot+1, h);
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
        else if (!isdigit(num)){
            break;
        }
    }

    if (arr.size() == 0){
        cout << "\nEmpty vector";
        exit(0);
    }
    else{
        quickSort(arr, 0, arr.size()-1);
        disp(arr);
    }

    return 0;
}