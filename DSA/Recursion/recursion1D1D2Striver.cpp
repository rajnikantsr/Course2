#include<iostream>
#include<math.h>
using namespace std;

int factorial(int n) {
    if(n == 0)
        return 1;
    int smallProb = factorial(n-1);
    int biggProb = n * smallProb;
    return biggProb;
    // return factorial(n-1) * n;
}
int power(int n) {
    if(n == 0) 
        return 1;  
    int small = power(n-1);
    int big = 2 * small;
    return big;
}
void counting(int n, int sum = 0) {
    if(n == 0) { 
        cout << "Sum : " << sum << endl;
        return ;
    }
    counting(n-1, sum+n);
    cout << n << " ";
}
void reachHome(int src, int dest) {
    cout << "Source " << src << " Destination " << dest << endl;
    if(src == dest) {
        cout << "Pahuch gye" << endl;
        return ;
    }
    src++;
    reachHome(src, dest);
}
int fib(int n) {
    if(n == 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    int ans = fib(n-1) + fib(n-2);
    return ans;
}
int countDistinctWayToClimbStairs(int n) {
    // if(n < 0) {
    //     return 0;
    // }
    // if(n == 0) {
    //     return 1;
    // }
    if(n<=2) {
        return n;//Base case : if stairs = 1 then way = 1 and stairs = 2 way = 2
    }
    int ans = countDistinctWayToClimbStairs(n-1) + countDistinctWayToClimbStairs(n-2);
    return ans;
} 
void sayDigit(int n, string arr[]) {
    if(n == 0) {
        return ;
    }
    int digit = n%10;
    n = n/10;
    sayDigit(n, arr);
    cout << arr[digit] << endl;
}
void namePrint(int m, string name) {
    if(m<=0) {
        return ;
    }
    cout << name << endl;
    namePrint(m-1, name);
}
void reverseArr(int rev[], int S, int L) {
    if(S>=L) {
        return ;
    }
    swap(rev[S], rev[L]);
    reverseArr(rev, S+1, L-1);
}
void printArray(int rev[], int size, int index = 0) {
    if (index == size) {
        return;
    }
    cout << rev[index] << " ";
    printArray(rev, size, index + 1);
}
bool checkPalindrome(string &newArray, int i, int n) {
    if(i>n/2) return true;
    if(newArray[i] != newArray[n-i-1]) return false;
        return checkPalindrome(newArray, i+1, n);
}
int main() {
    // int n;
    // cin >> n;
    // cout << factorial(n) << endl;
    // cout << power(n) << endl;
    // counting(n);
    // cout << endl;
    // reachHome(1, 10);
    // cout << "Nth fibonacci number : " << fib(n) << endl;
    // cout << countDistinctWayToClimbStairs(n)  << endl;
    // string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    // sayDigit(n, arr);
    // int m;
    // string name;
    // cout << "Enter the number of times to print: ";
    // cin >> m;
    // cout << "Enter the string to print: ";
    // cin >> name;
    // namePrint(m, name);
    // int rev[] = {1, 3, 5, 7, 9, 3};
    // int k = sizeof(rev)/sizeof(rev[0]);
    // reverseArr(rev, 0, k-1);
    // printArray(rev, k);
    string newArray = "MADAM";
    int l = newArray.size();
    cout << checkPalindrome(newArray, 0, l);
    return 0;
}