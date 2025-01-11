#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// vector<bool> sieveOfEratosthenes(int n) {
//     vector<bool> prime(n+1, true);
//     prime[0] = prime[1] = false;
//     for (int i = 2; i <= n/2; i++) {
//         if (prime[i]) {
//             for (int j = 2*i; j <= n; j += i) {
//                 prime[j] = false;
//             }
//         }
//     }
//     return prime;
// }

// int isPrime(int n) {
//     int cnt = 0;
//     vector<bool> prime(n+1, true);
//     prime[0] = prime[1] = false;
//     for(int i =2; i<n; i++) {
//         if(prime[i]) {
//             cnt++;
//             for(int j = 2*i; j<n; j+=i) {
//                 prime[j] = false;
//             }
//         }
//     }
//     return cnt;
// }
int gcd(int a, int b) {
    // if(a == 0) {
    //     return b;
    // } 
    // if(b == 0) {
    //     return a;
    // }
    // while(a!=b) {
    //     if(a>b) {
    //         a = a-b;
    //     } else {
    //         b = b-a;
    //     }
    // }
    // return a;
    while(b!=0) {
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
} 
// int modularExponentiations(int x, int a, int b) {
//     int res = 1;
//     while(a>0) {
//         if (a & 1) {
//             res = ((1LL) * (res) * (x)%b) % b;
//         }
//         x = (1LL * (x)%b * (x)%b)%b;
//         a = a >> 1;//Means divided by 2
//         }
//         return res;
// }

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

void segmentedSieve(int l, int h) {
    int sq = sqrt(h);
    vector<int> primes = sieveOfEratosthenes(sq);
    vector<bool> isPrime(h - l + 1, true);
    for (int p : primes) {
        int start = (l / p) * p;
        if (start < l) {
            start += p;
        }
        for (int i = start; i <= h; i += p) {
            isPrime[i - l] = false;
        }
    }
    for (int i = l; i <= h; i++) {
        if (isPrime[i - l]) {
            cout << i << " ";
        }
    }
}
int countDivisibleBy(int n, int start, int end) {
    if(start%n == 0) {
        start = start;
    } else {
        start = start + (n-start%n);
    }
    if(end%n == 0) {
        end = end;
    } else {
        end = end - (end%n);
    }
    if(start > end) {
        return 0;
    }
    return (end-start)/n+1;
}
int countNumbers(int start, int end) {
    int count5 = countDivisibleBy(5, start, end);
    int count7 = countDivisibleBy(7, start, end);
    int count35 = countDivisibleBy(35, start, end);
    return count5 + count7 - count35;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<bool> primes = sieveOfEratosthenes(n);
    if(primes[n]) {
        cout << n << "->" << "Is a prime number" << endl;
    } else {
        cout << n << " -> " << "Not a prime number" << endl;
    }
    // if(n == isPrime(n)) {
    //     cout << "True" << endl;
    // } else {
    //         cout << "False" << endl;
    // }  
    // int a, b;
    // cin >> a >> b;
    // int ans = gcd(a, b);
    // cout << "GCD of a and b : " << ans << endl;
    // cout << "LCM of a and b : " << (a*b)/ans << endl;
    // int y, c, d;
    // cin >> y >> c >> d;
    // cout << "(x to the power a)%b : " << modularExponentiations(y, c, d);
    // int low = 49999900;
    // int high = 50000000;
    
    // cout << "Primes in range [" << low << ", " << high << "] are: ";
    // segmentedSieve(low, high);
    // int start, end;
    // cout << "Enter Your range for finding divisible of numbers : ";
    // cin >> start >> end;
    // int count1 = countNumbers(start, end);
    // int count2 = countNumbers(start, end);
    // int count3 = countNumbers(start, end);
    // cout << "Numbers between start and end divisible by 5 and 7 : " << count1 + count2 - count3 << endl;
    return 0;
}