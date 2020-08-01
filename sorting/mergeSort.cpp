/*
Best Case- O(nlog(n))
Average Case- O(nlog(n))
Worst Case- O(nlog(n))
*/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int h){
    int i,j,k;
    int n1 = mid-l+1;
    int n2 = h-mid;

    //create temorary arrays
    int left[n1], right[n2];

    //copy elements into the temporary arrays
    for(i=0;i<n1;i++)
        left[i] = arr[l+i];

    for(j=0;j<n2;j++)
        right[j] = arr[mid+1+j];

    i=0;
    j=0;
    k=l;

    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }

    //copy the remaining elements
    while(i < n1){
        arr[k++] = left[i++];
    }

    while(j < n2){
        arr[k++] = right[j++];
    }
}

/*
Divide the array into 2 halves and keep on dividing them until there are just 2 elements
Then compare those elements and sort them
Then merge the 2 subarrays and sort them as well
This is a recursive call
*/
void mergeSort(vector<int> &arr, int l, int h){
    if(l<h){
        int mid = l+(h-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
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
    }else{
        mergeSort(arr, 0, arr.size() - 1);
        disp(arr);
    }

    return 0;
}