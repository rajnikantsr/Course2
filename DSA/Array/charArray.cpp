#include<iostream>
#include<vector>
#include<string>
using namespace std;

// int getLength(char name[]) {
//     int count = 0;
//     for(int i = 0; name[i] != '\0'; i++) {
//         count++;
//     }
//     return count;
// }
// void revString(char name[], int length) {
//     int s = 0;
//     int e = length-1;
//     while(s<e) {
//         swap(name[s++], name[e--]);
//     }
// }
// char toLowercase(char ch) {
//     if(ch>='a' && ch<='z') {
//         return ch;
//     } else {
//         char temp = ch - 'A' + 'a';
//         return temp;
//     }
// }
// bool getPalindrome(char name[], int n) {
//     int s = 0;
//     int e = n-1;
//     while(s<=e) {
//         if(toLowercase( name[s] ) != toLowercase( name[e] )) {
//             return 0;
//         }
//         else if(name[s] == '\0') {
//             s++;
//         }
//         else if(name[e] == '\0') {
//             e--;
//         } else {
//             // if(!isalnum(name[s]) && s<e) { //alnum is predefined keyword(means char. is alph & num or not)
//             //     s++;
//             // }
//             // else if(!isalnum(name[e]) && s<e) {
//             //     e--;
//             // }
//              if(name[s] <= 'a' && name[s] >= 'z' || name[e] <= 'A' && name[e] >= 'Z') {
//                 s++;
//                 e--;
//             }
//         return 1;
//         }
//     }
// }
//character is valid or not
// bool valid(char ch) {
//     if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
//         return 1;
//     }
//     return 0;
// }
// //convert upper case to lower case
// char toLowercase(char ch) {
//     if(ch>='a' && ch<='z') {
//         return ch;
//     } else {
//         char temp = ch - 'A' + 'a';
//         return temp;
//     }
// }
// //checking palindrome or not
// bool checkPalindrome(string str) {
//     int s = 0;
//     int e = str.length()-1;
//     while(s<=e) {
//         if(str[s] != str[e] ) {
//             return 0;
//         } else {
//                 s++;
//                 e--;
//         }
//         return 1;
//     }
// }
// // Implicit calling
// bool isPalindrome(string str) {
//     //Removing faltu character
//     string temp = " ";
//     for(int j = 0; j<str.size(); j++) {
//         if(valid(str[j])) {
//             temp.push_back(toLowercase(str[j]));
//         }
//     }
//     // for(int j = 0; j<temp.size(); j++) {
//     //     temp[j] = toLowercase(temp[j]);
//     // }
//     return checkPalindrome(temp);
// }

//Printing reverse of words of string
vector<string> reverseWords(vector<string> words) {
    vector<string> reversedWords;
    for (const auto& word : words) {
        string reversedWord = "";
        for (int i = word.length() - 1; i >= 0; i--) {
            reversedWord += word[i];
        }
        reversedWords.push_back(reversedWord);
    }
    return reversedWords;
}
vector<string> splitString(string str) {
    vector<string> words;
    string word = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '\0') {
            if (word != "") {
                words.push_back(word);
                word = "";
            }
        } else {
            word += str[i];
        }
    }
    //To printing last word
    if (word != "") {
        words.push_back(word);
    }
    return reverseWords(words);
}

int main() {
    // char name[20];
    // cout << "Enter your name : ";
    // cin >> name;
    // // name[5] = '\0';
    // cout << "Your name is : ";
    // cout << name << endl;
    // int length = getLength(name);
    // cout << "length : " << length << endl;
    // revString(name, length);
    // cout << "Your Reverse name is : ";
    // cout << name << endl;
// solve by using character array
    // cout << "Palindrome or not : " << getPalindrome(name, length) << endl;
    // cout << "Upper case to lower case character : " << toLowercase('A') << endl;
// solving by string
    // string str = "";
    // cout << "Enter a string: ";
    // cin >> str;

    // bool palindrome = checkPalindrome(str);
    // if(palindrome) {
    //     cout << "Palindrome";
    // } else {cout << "Not a palindrome";}
    // cout << palindrome;
    // std::string S("Hey! How are you?");
    // for(int i = 0; S[i] != '\0'; ++i)
    // std::cout << S[i];
    string str2 = "My name is Rajnikant";
    vector<string> result = splitString(str2);
    for (const auto& word : result) {
        cout << word << " ";
    }
    return 0;
}