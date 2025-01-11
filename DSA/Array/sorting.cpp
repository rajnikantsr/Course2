#include<iostream>
using namespace std;
//Selection sort
int selectionSort(int arr[], int a) {
    for(int i = 0; i<a-1; i++) {
        int minIndex = i;
        for(int j = i+1; j<a; j++) {
            if(arr[j]  < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    return arr[a-2];
}
//Bubble sort
int bubbleSort(int arr[], int b) {
    for(int i = 1; i<b; i++) {
        bool swapped = false;
        for(int j = 0; j<b-i; j++) {
            //proceed element till (b-i)th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                //if swap use then return true else false
                swapped = true;
            }
        }
        //already sorted
        if(swapped == false) {
            break;
        }
    }
    return arr[b-2];
}
//Insertion sort
int insertionSort(int arr[], int c) {
    for(int i = 0; i<c; i++) {
        int temp = arr[i];
        int j;
        for(j = i-1; j>0; j++) {
            if(arr[j] > temp) {
                //shifting array
                arr[j+1] = arr[j];
            } else {//ruk jao
                break;
            }
        }
        arr[j+1] = temp;
    }
    return arr[c-2];
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int a = sizeof(arr)/sizeof(arr[0]);
    int sorting1 = selectionSort(arr, a);
    cout << "Second maximum element in array1 : " << sorting1 << endl;
    int b = sizeof(arr)/sizeof(arr[0]);
    int sorting2 = bubbleSort(arr, b);
    cout << "Second maximum element in array2 : " << sorting2 << endl;
    int c = sizeof(arr)/sizeof(arr[0]);
    int sorting3 = insertionSort(arr, c);
    cout << "Second maximum element in array3 : " << sorting3 << endl;
    return 0; 
}