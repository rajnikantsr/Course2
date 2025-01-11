#include<iostream>
#include<vector>
#include<string>
using namespace std;

char getMaxOccChar(string s) {
    int arr[26] = {0};
    //create an array of count of character
    for(int i = 0; i<26; i++) {
        char ch = s[i];
        int number = 0;
        if(ch >= 'a' && ch <= 'z') {//lowercase
            number = ch - 'a';
        } else {//upper case
            number = ch - 'A';
        }
        arr[number]++;
    }
    //Find maximum occ. character
        int maxi = -1, ans = 0;
        for(int i = 0; i<26; i++) {
             if(maxi<arr[i]) {
                    ans = i;
                    maxi = arr[i];
           }
        }
        cout << "Index of Max occ. alphabet : " << ans << endl;
        return 'a' + ans;
}
string replaceSpace(string s) {
    string temp = "";
    for(int i = 0; i<s.length(); i++) {
        if(s[i] == ' ') {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        } else {
            temp.push_back(s[i]);
        }
    }
    return temp;
}
// string replaceSpace(string s) {
//     for(int i = 0; i<s.length(); i++) {
//         if(s[i] == ' ') {
//             s[i] = '@';
//         } else {
//             s[i] = s[i];
//         }
//     }
//     return s;
// }
// string removeOccurences(string str1, string str2) {
//     while(str1.length() != 0 && str1.find(str2) < str1.length()){
//         str1.erase(str1.find(str2), str2.length());
//     }
//     return str1;
// }
// Checking Presence of permutation of string S1 in S2
bool checkEqual(int a[26], int b[26]) {
    for(int i = 0; i<26; i++) {
        if(a[i] != b[i]) {
        return 0;
        }
    }
    return 1;
}
bool checkingPermutation(string s1, string s2) {
    //character count array
    int count1[26] = {0};//Responsible for space complexity
    for(int i = 0; i<s1.length(); i++) {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    //traverse s2 string in window of size s1length and compare
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};//Responsible for space complexity
    // running for first window
    while(i<windowSize && i<s2.length()) {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if( checkEqual(count1, count2) ) {
        return 1;
    }
    
//aage widow process kro
    while(i<s2.length()) {
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i-windowSize];
        index = oldChar - 'a';
        count2[index]--;
        i++;
        if( checkEqual(count1, count2) ) {
            return 1;
        }
    }
    return 0;
}
string removeDuplicates(string s) {
    string temp = "";
    int i = 0;
    while(i < s.length()){
        if(temp.empty() || s[i] != temp.back()){
            temp.push_back(s[i]);  // push the current character
        } else{
            temp.pop_back(); // pop last character of the temp string
        }
        i++;
    }
    return temp;
}
string compress(vector<char>& chars) {
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();
    while(i<n) {
        int j = i+1;
        while(j<n && chars[i] == chars[j]) {
            j++;
        }
        /*Yaha kab aaoge
        jab poora vector traverse kardia 
        ya dusra character aa gya*/
        //old character store kar dia
        chars[ansIndex++] = chars[i];
        int count = j-i;
        if(count > 1) {
            //converting counting into single digit
            string cnt = to_string(count);
            for(char ch: cnt) {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    chars.resize(ansIndex); // Resize the vector to the new size
    string result(chars.begin(), chars.end()); // Convert vector to string
    return result;

}
int main() {
    // string s;
    // getline(cin, s);//Use to take input string with spaces
    // cout << getMaxOccChar(s) << endl;
    // cout << s;
    // cout << "New string is : " << replaceSpace(s) << endl;
    // string str1 = "daabcbaabcbc";
    // string str2 = "abc";
    // cout << "After removing every part from str1 : " << removeOccurences(str1, str2);
    // string s1 = "ab";
    // string s2 = "eiadabooo";
    // cout << "Permutation of string s1 in s2 : " << checkingPermutation(s1, s2) << endl;
    // string s3 = "abbacd";
    // cout << "Original string: " << s3 << endl;
    // string temporary = removeDuplicates(s3);
    // cout << "After removing duplicate element : " << temporary << endl;
    vector<char> chars= {'a', 'a', 'a', 'b', 'c', 'c', 'd', 'd', 'd', 'd'};
    cout << "After compressing String : " << compress(chars) << endl;
    return 0;

}


