#include <iostream>
using namespace std;

void merge(int *arr1, int s, int e) {
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int mainArrayIndex = s;
    for(int i = 0; i<len1; i++) {
        first[i] = arr1[mainArrayIndex++];
    }
    mainArrayIndex = mid+1;
    for(int i = 0; i<len2; i++) {
        second[i] = arr1[mainArrayIndex++];
    }
    //merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr1[mainArrayIndex++] = first[index1++];
        }
        else {
            arr1[mainArrayIndex++] = second[index2++];
        }
    }
    while(index1 < len1) {
        arr1[mainArrayIndex++] = first[index1++]; 
    }
    while(index2 < len2) {
        arr1[mainArrayIndex++] = second[index2++];
    }
    delete[] first;
    delete[] second;

}
void mergeSort(int *arr1, int s, int e) {
    if(s >= e) {
        return;
    }
    int mid = s + (e-s)/2;
    //Sorting left part
    mergeSort(arr1, s, mid);
    //sorting left part
    mergeSort(arr1, mid+1, e);
    //merging both part
    merge(arr1, s, e);
}
int main() {
    int arr1[] = {1, 4, 3, 8, 5, 2};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    mergeSort(arr1, 0, n-1);
    for(int i = 0; i<n; i++) {
        cout << arr1[i] << " ";
    } cout << endl;
    return 0;
}