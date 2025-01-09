// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

const int N = 3;

void sortArr2D(int a[][N]);
void sortArr(int a[], int arrSize);
void printArr2D(int a[][N]);

int main() {
    int arr[N][N];

    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            cout << "Please enter element:" << endl;
            cin >> arr[row][column];
        }
    }

    cout << endl;
    printArr2D(arr);
    cout << endl;

    sortArr2D(arr);

    printArr2D(arr);
    cout << endl;

    return 0;
}

void sortArr(int a[], int arrSize) {
    int temp;

    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void sortArr2D(int a[][N]) {
    int tempArrSize = N * N;
    int tempArr[tempArrSize], tempArrIndex = 0;

    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            tempArr[tempArrIndex] = a[row][column];
            tempArrIndex++;
        }
    }

    sortArr(tempArr, tempArrSize);

    tempArrIndex = 0;
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            a[row][column] = tempArr[tempArrIndex];
            tempArrIndex++;
        }
    }
}

void printArr2D(int a[][N]) {
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            cout << a[row][column] << " ";
        }
        cout << endl;
    }
}
