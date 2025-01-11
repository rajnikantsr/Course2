#include<iostream>
#include<math.h>
using namespace std;
int binToDec(int n) {
    int ans = 0;
    int i = 0;
    while(n != 0) {
        int bit = n%2;
        ans = (bit * pow(10, i)) + ans;
        n = n/10;
        i++;
    }
    return ans;
}   
int main()
    {
        int n = -6;
        int temp = -1*n;
        int res = binToDec(temp);
        cout << res << endl;
    }