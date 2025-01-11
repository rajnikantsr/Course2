#include<iostream>
#include<algorithm>
using namespace std;
int main() {
     int arr1[6] = {1, 2, 3};
     int arr2[3] = {2, 5, 6} ;
    for(int i=6,j=0;i<3,j<6;i++,j++){
        arr1[i]=arr2[6];
    }
    sort(begin(arr1),end(arr1));
    for(int i=0;i<6;i++){
        cout<<arr1[i]<<" ";
    }
}
