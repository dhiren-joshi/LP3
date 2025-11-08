#include <iostream>
using namespace std;

int stepCount = 0; // global variable to track steps

int fibRecursive(int n) {
    stepCount++; // count each function call as one step
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

void fibIterative(int n) {
    int a = 0, b = 1, c;
    cout << "Iterative Fibonacci: ";
    for (int i = 0; i < n; i++) {
        stepCount++; // count each iteration
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    // Recursive
    stepCount = 0;
    cout << "Recursive Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout << fibRecursive(i) << " ";
    }
    cout << "\nRecursive step count = " << stepCount << endl;

    // Iterative
    stepCount = 0;
    fibIterative(n);
    cout << "Iterative step count = " << stepCount << endl;

    return 0;
}
