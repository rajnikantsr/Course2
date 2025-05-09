#include <iostream>
using namespace std;

class Nstack {
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freeSpot;

public:
    Nstack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize top array
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize next array
        for (int i = 0; i < s; i++) {
            next[i] = i + 1;
        }
        next[s - 1] = -1; // Update last index

        // Initialize freeSpot
        freeSpot = 0;
    }

    // Pushes 'x' into the Mth stack
    bool push(int x, int m) {
        // Check overflow
        if (freeSpot == -1) {
            return false;
        }

        // Find index
        int index = freeSpot;
        freeSpot = next[index];

        // Insert element into array
        arr[index] = x;

        // Update next
        next[index] = top[m - 1];

        // Update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth stack
    int pop(int m) {
        // Check underflow condition
        if (top[m - 1] == -1) {
            return -1;
        }

        int index = top[m - 1];

        // Update top to the next element in the stack
        top[m - 1] = next[index];

        // Update freeSpot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    // Destructor to free allocated memory
    ~Nstack() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    Nstack stacks(3, 6); // 3 stacks in an array of size 6

    // Test cases
    stacks.push(10, 1);
    stacks.push(20, 2);
    stacks.push(30, 3);
    stacks.push(40, 1);
    stacks.push(50, 2);
    stacks.push(60, 3);

    cout << "Popped from stack 1: " << stacks.pop(1) << endl;
    cout << "Popped from stack 2: " << stacks.pop(2) << endl;
    cout << "Popped from stack 3: " << stacks.pop(3) << endl;

    return 0;
}
