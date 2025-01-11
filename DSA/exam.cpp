#include<iostream>
#include<string> 
using namespace std;
string convert(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (i == 0 || str[i - 1] == ' ') {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        } else {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }
    }
    return str;
}
// int maxiSize(string str) {
//     int maxSize = 0;
//     int currentSize;
//     for(int i = 0; i<str.length(); i++) {
//         if(str[i] >= 'a' && str[i] <= 'z' && str[i] >= 'A' && str[i] <= 'Z' && str[i] != ' ') {
//             current += 1;
//         }
//     }
//     if(currentSize > maxSize) {
//         maxSize = currentSize;
//         currentSize = 0
//     }
// }
int maxiSize(string str) {
    int maxSize = 0;
    int currentSize = 0;
    for(int i = 0; i < str.length(); i++) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {  // Check for letters only
            currentSize += 1;
        } else {
            if(currentSize > maxSize) {  // jab str[i] == ' ' tab maxSize = currentSize
                maxSize = currentSize;
            }
            currentSize = 0;  // fir currentSize karoge na?
        }
    }
    if(currentSize > maxSize) {  // abb maan lo ki 4 word ka string hai toh unme se max size nikalna hai na isle wapis likha
        maxSize = currentSize;
    }
    return maxSize;
}


int main() {
/*    string str;
    getline(cin, str);
    cout << convert(str) << " ";
    return 0;*/
    string str;
    getline(cin, str);
    cout << maxiSize(str) << " ";
    return 0;
}
