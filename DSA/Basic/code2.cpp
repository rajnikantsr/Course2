#include<iostream>

using namespace std;
int calculatingNCR(int n, int r) {
    int res = 1;
    for(int i = 0; i<r; i++) {
        res = res*(n-i)/(i+1);
    }
    return res;
}
int main() {
// // Print number from 1-n and their sum:-
//     int n, m;
//     cout << "Enter no. : ";
//     cin >> n;
//     cout << "Enter no. for even sum : ";
//     cin >> m;
    
//     int i=1;
//     int sum = 0;
//     int j=2;
//     int sume = 0;
//     while(i<=n) {
//         cout << i << endl;
//         sum = sum + i;
//         i = i+1;
//     }
//     cout << "Value of Sum is : " << sum << endl;
//     while(j<=m) {
//         cout << j << endl;
//         sume = sume + j;
//         j = j+2;
//     }
//     cout << "Value of Even no's. sum : " << sume << endl;
// //convert temp. from celcius to fahrenheit
//     float C;
//     cout << "Enter temperature in celcius : ";
//     cin >> C;
//     float temp = 1.8 * C + 32;
//     cout << "Temp. in fahrenheit is : " << temp << endl;
//Given no. is prime or not
    // int o;
    // cout << "Enter no : ";
    // cin >> o;
    // int k = 2;
    // while(k<o) {
    //     if(o % k == 0) {
    //         cout << "Not a prime no. for " << k << endl;
    //     }
    //     else {
    //         cout << "A prime no. for  " << k << endl;
    //     }
    //     k = k+1;
    // }
// //Pattern1
//     int p;
//     cout << "Enter no. 1 : ";
//     cin >> p;
//     int a = 1;
//     while(a<=p) {
//         int b = 1;
//         while(b<=p) {
//             cout << '*';
//             b++;
//         }
//         cout << endl;
//         a++;
//     }
// //Pattern2
// int q;
// cout << "Enter no. 2 : ";
// cin >> q;
// int c = 1;
// while(c<=q) {
//         int d = 1;//If j=i then it print in triangle format
//         while(d<=q) {
//         cout << c;
//         d = d+1;
//         }
//         cout << endl;
//         c++;
//     }
// //pattern3
// int r;
// cout << "Enter no. 3 : ";
// cin >> r;
// int e = 1;
// while(e<=r) {
//     int f=1;
//     while(f<=r) {
//         cout << f;
//         f++;
//     }
//     cout << endl;
//     e++;
// }
// //pattern4
// int s;
// cout << "Enter no. 4 : ";
// cin >> s;
// int g=1;
// while(g<=s) {
//     int h=s;
//     while(h>=1) {
//         cout << h;
//         h--;
//     }
//     cout << endl;
//     g++;
// }
// //pattern5
// int t;
// cout << "Enter no. 5 : ";
// cin >> t;
// int i=1;
// int count = 1;
// while(i<=t) {
//     int j=1;
//     while(j<=t) {
//         cout << count << "\t";
//         count++;
//         j++;
//     }
//     cout << endl;
//     i++;
// }
// //pattern6
// int u;
// cout << "Enter no. 6 : ";
// cin >> u;
// int k=1;
// while(k<=u) {
//     int l=1;
//     while(l<=k) {// col <= row
//         cout << '*';
//         l++;
//     }
//     cout << endl;
//     k++;
// }
// //pattern7
// int v;
// cout << "Enter no. 7 : ";
// cin >> v;
// int m=1;
// while(m<=v) {
//     int n=1;
//     while(n<=m) {
//         cout << m;
//         n++;
//     }
//     cout << endl;
//     m++;
// }
// //pattern8
// int w;
// cout << "Enter no. 8 : ";
// cin >> w;
// int o=1;
// while(o<=w) {
//     int p=1;
//     int value = o;
//     while(p<=o) {
//         cout << value << "\t";// we cannot write cout << row << "\t" . It gives error
//         value++;
//         p++;
//     }
//     cout << endl;
//     o++;
// }
// //pattern9
// int  x;
// cout << " Enter no. 9 : ";
// cin >> x;
// int y=1;
// int count2 = 1;
// while(y<=x) {
//     int z=1;
//     while(z<=y) {
//         cout << count2 << "\t";
//         count2 = count2 +1;
//         z++;
//     }
//     cout << endl;
//     y++;
// }
// //pattern10
// int A;
// cout << "Enter no. 10 : ";
// cin >> A;
// int row =1;
// while(row <= A) {
//     int col = 1;
//     while(col<=row) {
//         cout << (row-col+1);
//         col = col+1;
//     }
//     cout << endl;
//     row = row+1;
// }
// //pattern11
// int B;
// cout << "Enter no. 11 : ";
// cin >> B;
// int row1 = 1;
// while(row1 <= B) {
//     int col1 = 1;
//     char C = 'A' + row1 - 1;
//     while(col1 <= B) {
//         cout << C << "\t";
//         col1 = col1 + 1;
//     }
//     cout << endl;
//     row1 = row1 + 1;
// }
// //pattern12
// int Z;
// cout << "Enter no. 12 : ";
// cin >> Z;
// int row3 = 1;
// char Y = 65;
// while(row3 <= Z) {
//     int col3 =1;
//     while(col3 <= Z) {
//         cout << Y << "\t";
//         Y = Y + 1;
//         col3 = col3 + 1;
//     }
//     cout << endl;
//     row3 = row3 + 1;
// }
// //pattern13
// int D;
// cout << "Enter no. 13 : ";
// cin >> D;
// int row2 =1;
// char E = 65;
// while(row2 <= D) {
//     int col2 = 1;
//     while(col2<= row2) {
//         cout << E << "\t";
//         E = E+1;
//         col2 = col2 + 1;
//     }
//     cout << endl;
//     row2 = row2 + 1;
// }
// //pattern14
// int F;
// cout << "enter no. 14 : ";
// cin >> F;
// int row4 = 1;
// while(row4<=F) {
//     int col4 = 1;
//     while(col4<=F) {
//         char ch1 = 'A' + col4 - 1;
//         cout << ch1 << "\t";
//         col4 = col4 + 1;
//     }
//     cout << endl;
//     row4 = row4 + 1;
// }
// // pattern15,17
// int G;
// cout << "Enter no. 15 : ";
// cin >> G;
// int row5 = 1;
// while(row5<=G) {
//     int col5 = 1;
//     int val1 = row5;
//     while(col5<=G) {//col5<=row5 then triangular pattern forms
//         char ch2 = 'A' + val1 -1;//M-2 'A' + i + j -2
//         cout << ch2 << "\t";
//         col5 = col5 + 1;
//         val1 = val1 + 1;
//     }
//     cout << endl;
//     row5 = row5 + 1;
// }
// //pattren16
// int H;
// cout << "Enter no. 16 : ";
// cin >> H;
// int row6 = 1;
// while(row6<=H) {
//     int col6 = 1;
//     while(col6<=row6) {
//         char ch2 = 'A'+ row6 - 1;
//         cout << ch2 << "\t";
//         col6 = col6 + 1;
//     }
//     cout << endl; 
//     row6 = row6 + 1;
// }
// //pattern18
// int I;
// cout << "Enter no. 18 : ";
// cin >> I;
// int row7 = 1;
// while(row7<=I) {
//     int col7 = 1;
//     char ch3 = 'A' + I - row7;
//     while(col7<=row7) {
//         cout << ch3;
//         ch3 = ch3 + 1;
//         col7 = col7 + 1;
//     }
//     cout << endl;
//     row7 = row7 + 1;
// }
// //pattern19
// int J;
// cout << "Enter no. 19 : ";
// cin >> J;
// int row8 = 1;
// while(row8<=J) {
//     int col8 = 1;
//     while(col8<=row8) {
//         char ch4 = 'A' + col8 - 1;
//         cout << ch4;
//         col8 = col8 + 1;
//     }
//     cout << endl;
//     row8 = row8 + 1; 
// }
// //pattern20
// int K;
// cout << "Enter no. 21 : ";
// cin >> K;
// int row9 = 1;
// while(row9<=K) {
//     //space print karo
//     int space1 = K-row9;
//     while(space1) {
//         cout << " ";
//         space1 = space1 -1;
//     }
//     int col9 = 1; 
//     //star print karo
//     while(col9<=row9) {
//         cout << "*";
//         col9 = col9 + 1;
//     }
//     cout << endl;
//     row9 = row9 + 1;
// }
// //pattern 21
// int L;
// cout << "Enter no. 21 : ";
// cin >> L;
// int row10  = 1;
// while(row10<=L) {
//     int col10 = L;
//     while(col10>=row10) {
//         cout << "*";
//         col10 = col10 - 1;
//     }
//     cout << endl;
//     row10 = row10 + 1;
// }
// //pattern22
// int M;
// cout << "Enter no. 22 : ";
// cin >> M;
// int row11 = 1;
// while(row11<=M) {
//     int space2 = 1;
//     while(space2<=row11-1) {
//         cout << " ";
//         space2 = space2 + 1;
//     }
//     int col11 = M;
//     while(col11>=row11) {
//         cout << "*";
//         col11 = col11 - 1;
//     }
//     cout << endl;
//     row11 = row11 + 1;
// }
// //pattern23
// int N;
// cout << "Enter no. 23 : ";
// cin >> N;
// int row12 = 1;
// while(row12<=N) {
//     int space3 = 1;
//     while(space3<=row12-1) {
//         cout << " ";
//         space3 = space3 + 1;
//     }
//     int col12 = N;
//     while(col12>=row12) {
//         cout << row12;
//         col12 = col12 - 1;
//     }
//     cout << endl;
//     row12 = row12 + 1;
// }
// //pattern 24
// int O;
// cout << "Enter no. 24 : ";
// cin >> O;
// int row13 = 1;
// while(row13<=O) {
//     int space4 = 1;
//     while(space4<=O-row13) {
//         cout << " ";
//         space4 = space4 + 1; 
//     }
//     int col13 = 1;
//     while(col13<=row13) {
//         cout << row13;
//         col13 = col13 + 1;
//     }
//     cout << endl;
//     row13 = row13 + 1;
// }
// //pattern25
// int P;
// cout << "Enter no. 25 : ";
// cin >> P;
// int row14 = 1;
// while(row14<=P) {
//     int space5 = 1;
//     while(space5<=row14-1) {
//         cout << " ";
//         space5 = space5 + 1;
//     }
//     int col14 = P;
//     int val2 = row14;
//     while(col14 >= row14) {
//         cout << val2;
//         val2 = val2 + 1;
//         col14 = col14 - 1;
//     }
//     cout << endl;
//     row14 = row14 + 1;
// }
// //pattern26
// int Q;
// cout << "Enter no. 26 : ";
// cin >> Q;
// int row15 = 1;
// int val3 = 1;
// while(row15<=Q) {
//     int space6 = 1;
//     while(space6<=Q-row15) {
//         cout << " " << "\t";
//         space6 = space6 + 1;
//     }
//     int col15 = 1;
//     while(col15<=row15) {
//         cout << val3 << "\t";
//         val3 = val3 + 1;
//         col15 = col15 + 1;
//     }
//     cout << endl;
//     row15 = row15 + 1;
// }
// //pattern27
// int R;
// cout << "Enter no. 27 : ";
// cin >> R;
// int row16 = 1;
// while(row16<=R) {
//     int space6 = 1;
//     while(space6 <= R-row16){
//         cout << " ";
//         space6 = space6 +1;
//     }
//     int col16 = 1;
//     while(col16<=row16) {
//         cout << col16;
//         col16 = col16 + 1;
//     }
//     int col16a = 1;
//     while(col16a<=row16-1) {
//         cout << col16a;
//         col16a = col16a + 1;
//     }
//     cout << endl;
//     row16 = row16 + 1;
// }
// //pattern28
// int S;
// cout << "Enter no. 28 : ";
// cin >> S;
// int row17 = 1;
// while(row17<=S) {
//     int col17 = S;
//     while(col17>=row17) {
//         cout << S-col17+1;
//         col17 = col17 - 1;
//     }
//     col17 = S;
//     int col17a = 1;
//     while(col17a<=2*row17-2) {
//         cout << "*";
//         col17a = col17a + 1;
//     }
//     while(col17>=row17) {
//         cout << col17-row17+1;
//         col17 = col17 - 1;
//     }
//     cout << endl;
//     row17 = row17 + 1;
// }
//Printing pascal triangle
int rows;
cout << "Enter number of rows: ";
cin >> rows;
for(int i = 0; i<rows; i++) {
    for(int j = 0; j<rows-i-1; j++) {
        cout <<  " ";
    }
    for(int j = 0; j<=i; j++) {
            cout << calculatingNCR(i, j) << " ";
    }
    cout << endl;
    }
return 0;
}

