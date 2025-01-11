#include<iostream>
using namespace std;

void knowValue(int *p) {
    cout << *p << endl;
    cout << p << endl;
}
void update(int **p2) {
    // p2 = p2 + 1;
    // cout << "Inside function : " << j << endl;
    // *p2 = *p2 + 1;
    **p2 = **p2 + 1;
}
int getSum(int *arr, int n) {// *arr or arr[] 
    // cout << "Size of arr : " << sizeof(arr) << endl;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += i[arr];//sum += arr[i]
    }
    return sum;
}
int main() {
/*   int num = 5;
    int *ptr = &num;
    int *ptr2 = 0;
    ptr2 = &num;
    cout << "Printing value in num variable : " << num << endl;//Printing value to which num mapped with
    cout << "Printing address of num : " << ptr << endl;//printing address of num
    cout << "Printing value at address of pointer by num :" << *ptr << endl;
    cout << "Printing address of num :" << ptr2 << endl;
    cout << "Size of num : " << sizeof(num) << endl;
    cout << "Size of pointer : " << sizeof(ptr) << endl;

    int *p;// Bad practice 
    cout << "Garbage value : " << *p << endl; // If we declare value of *p which is not declared first 
*/
/*  int num = 5;
    int *ptr3 = &num;
    cout << "Value of num before : " << num << endl;
    (*ptr3)++;// Incresases the value at address of pointer by 1
    cout << "Value of num after : " << num << endl;
    int **ptr4 = &ptr3 ;
    cout << ptr3 << "__" << ptr4 << endl;
    cout << *ptr3 << "__" << **ptr4 << endl;*/
    // int i = 3;
    // int *t = &i;
    // *t = *t + 1;
    // t = t + 1;
    // cout << *t << endl;
    // cout << t << endl;// Let if it print address of i = 100
    // t = t + 1;
    // cout << t << endl;// Then it prints add. of i = 104
    // int arr[10] = {1, 3, 2, 8};
    // cout << "Address of 0th index of array : " << &arr[0] << endl;
    // cout << "Address of 0th index of array : " << arr << endl;
    // cout << "Value of Oth index : " << arr[0] << endl;
    // cout << "Value of Oth index : " << *arr << endl;
    /*  cout << "Value of 1st index : " << *(arr+1) << endl;
    cout << "Value of Oth + 1 index : " << (*arr)+1 << endl;
    cout << "Value of Oth index : " << *(i+arr) << endl;
    cout << "Value of Oth index : " << i[arr] << endl; */
/*    cout << "Size of arr : " << sizeof(arr) << endl;
    cout << "Size of arr's 1st index : " << sizeof(*arr) << endl;
    out << "Size of arr : " << sizeof(&arr) << endl;
    int *temp = &arr[3];
    cout << "Size of address of 3rd index : " << sizeof(temp) << endl;
    cout << "Size of value of address of 3rd index: " << sizeof(*temp) << endl;
    cout << "Size of address of 3rd index : " << sizeof(&temp) << endl;*/
    // int arr1[10];
    // arr = arr + 1;//Gives error
 /*   cout << arr1 << endl;
    int *ptr1 = &arr1[0];
    ptr1 = ptr1 + 1;
    cout << ptr1 << endl; */
    // char ch[6] = "abcde";
    // cout << ch << endl;
    // char *c = &ch[0];
    // cout << c << endl;
 /*   char temp = 'z';
    char *ptr = &temp;
    cout << ptr << endl;
    char *p = "abcde";//It is risky */
    int j = 5;
    int *q1 = &j;
    int **q2 = &q1;
    // knowValue(p);
    cout << "Before update" << endl;
    cout << "Value inside i : " << j << endl;
    cout << "Value inside i : " << q1 << endl;
    cout << "Value inside i : " << q2 << endl;
    update(q2);
    cout << "After update" << endl;
    cout << "Value inside i : " << j << endl;
    cout << "Value inside i : " << q1 << endl;
    cout << "Value inside i : " << q2 << endl;
/*    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Sum of array element : " << getSum(arr + 2, 3) << endl;*/
    //Double pointer
    // int i = 5;
    // int *p1 = &i;
    // int **p2 = &p1;
    // cout << "Address of i : " << p1 << endl;
    // cout << "Value at address of i : " << *p1 << endl;
    // cout << "Address of p1 : " <<  p2 << endl;

    // cout << "Value inside i : " << i << endl;
    // cout << "Value inside i : " << *p1 << endl;
    // cout << "Value inside i : " << **p2 << endl;
    // cout << &p2 << endl;
}   
