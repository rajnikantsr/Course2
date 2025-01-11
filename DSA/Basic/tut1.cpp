#include<iostream>
using namespace std;//Shortcut to replace std::cout==cout 
//Diff. b/w local and global 
int glo = 6;
void sum() {
    int a;
    cout << glo;
}
int main() {
    int glo = 3;
    glo = 23;
    int a = 2, b = 3;
    char c = 'a';
    float pi = 3.14;
    bool is_true = true;
    sum();
    cout << glo << is_true;

    // cout << "Hello world!. \nHere the value of a : "<<a<< ". \nThe value of b : "<<b;
    // cout <<"\n Value of pi is : "<<pi;
    // cout <<"\n Value of c is : "<<c;

    return 0;
}