#include<iostream>
using namespace std;
int main() {
    // cout << "Hello World!" << endl;
    // int a = 'a';//Typecasting
    // cout << a << endl;
    // char b = 99;
    // cout << b << endl;//Typecasting
    // char c = 123455;
    // cout << c << endl;
    // float d = 5.983;
    // int e = int(d);
    // cout << e <<endl;
    // unsigned int f = -112;
    // cout << f << endl;
//----------------------------------------------
    //Conditional statement
    // int a;
    // cout << "Enter No. a : ";
    // cin >> a;
    // if(a>0) {
    //     cout << "a is positive";
    // }
    // else if(a<0) {
    //     cout << "a is negative";
    // }
    // else {
    //    cout << "a is zero";
    // }
//-----------------------------------------------
    // int a, b;
    // cout << "Enter the value of a : ";
    // cin >> a;
    // cout << "Enter the value of b : ";
    // cin >> b;
    // if(a>b) {
    //     cout << "Number a is greater =" << a << endl;
    // }
    // else {
    //     cout << "Number b is greater = " << b << endl;
    // }
//-----------------------------------------------
    // int a;
    // a = cin.get();
    // cout << "Value of a : " << a <<endl;//ASCII value of a
//-----------------------------------------------
    //  int a;
    // cout << "Enter No. a : ";
    // cin >> a;
    // if(a>20) {
    //     cout << "LOVE";
    // }
    // else if(a==24) {
    //     cout << "LOVELY";
    // }
    // else {
    //    cout << "BABBAR";
    // }
//code to distinguish upper , lower , and numeric value
char ch;
cout << "Enter your character : ";
cin >> ch;
if(ch>96 && ch<123) {
    cout << "Lower case"<< endl;
} else if(ch>64 && ch<91) {
    cout << "upper case"<< endl;
} else if(ch>47 && ch<58){
    cout << "Numeric value"<<endl;
} else {
    cout << "Symbol";
}
}