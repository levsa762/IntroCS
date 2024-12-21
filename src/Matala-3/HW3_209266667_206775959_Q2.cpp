// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

#define N 19

void longestSection(int A[], int size);

int main() {
    int A[N];

    for (int i = 0; i < N; i++) {
        cout << "Please enter a number: " << endl;
        cin >> A[i];
    }

    longestSection(A, N);

    return 0;
}

void longestSection(int A[], int size) {
    int maxLongestLength = 0, tempMaxLongestNum = 0, maxLongestFirstIndex;

    for (int i = 0, isFoundLongestNum = false; i < size -1; i++) {
        if ((A[i] > 0) && (A[i+1] > 0)) {
            if (!isFoundLongestNum) {
                maxLongestFirstIndex = i;
                isFoundLongestNum = true;
            }
            tempMaxLongestNum++;
        }
        else {
            isFoundLongestNum = false;
            if (tempMaxLongestNum > maxLongestLength) {
                maxLongestLength = tempMaxLongestNum;
            }
            tempMaxLongestNum = 0;
        }
    }

    if (maxLongestLength > 0) {
        maxLongestLength++;
    }

    cout << "The longest section starts at index " << maxLongestFirstIndex << ", its length is: ";
    cout << maxLongestLength << endl << "The section: ";
    for (int i = 0; i < maxLongestLength; i++) {
        cout << A[maxLongestFirstIndex + i] << " ";
    }
}
