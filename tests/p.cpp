#include <iostream>
using namespace std;

void printSpaces(int n) {
    if (n == 0) return;
    cout << " ";
    printSpaces(n - 1);
}

void printIncreasing(int n) {
    if (n == 0) return;
    printIncreasing(n - 1);
    cout << n;
}

void printDecreasing(int n) {
    if (n == 0) return;
    cout << n;
    printDecreasing(n - 1);
}

void printPattern(int n, int max) {
    if (n == 0) return;
    printPattern(n - 1, max);
    printSpaces(max - n);
    printIncreasing(n);
    printDecreasing(n - 1);
    cout << endl;
}

int main() {
    int n = 4;
    printPattern(n, n);
    return 0;
}