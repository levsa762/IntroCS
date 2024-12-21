// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

#define N 20

int curl(int a[], int size);
void printArray(int a[], int size);

int main() {
    int arrLength, iteration;

    cout << "Please enter the length of the array: " << endl;
    cin >> arrLength;

    int arr[arrLength];

    for (int i = 0; i < arrLength; i++) {
        cout << "Please enter a number: " << endl;
        cin >> arr[i];
    }

    // arrLength = 10;
    // // int arr[] = {1, 11, 4, 5, 2, 9, 4, 12, 17, 6};
    // int arr[] = {1, 3, 4, 5, 6, 5, 3, 17, 6, 10};

    cout << "The array is:" << endl;
    printArray(arr, arrLength);
    cout << endl << endl;

    cout << "The iterations performed on the array are: " << endl;
    iteration = curl(arr, arrLength);
    cout << endl;

    cout << "The amount of iterations performed on the array is: " << iteration << endl << endl;

    cout << "The new array is:" << endl;
    printArray(arr, arrLength);

    return 0;
}

int curl(int a[], int size) {
    // The tempArr array is of size 20 and all its elements are initialized to -1.
    // Its index expresses a number within the a[] array,
    // and its value will contain the position of the number within the a[] array.
    int num, arrIndex = 0, tempArr[N], numPos, firstIndexNumExist, numIteration = 0;
    bool isHandleNumExist = false;

    for (int tempArrIndex = 0; tempArrIndex < N; tempArrIndex++) {
        tempArr[tempArrIndex] = -1;
    }

    while (arrIndex < size) {
        cout << "(Num: " << a[arrIndex] << ", Index: " << arrIndex << ") " << endl;

        num = a[arrIndex];
        numPos = tempArr[num];

        // Check if a[i] (number) has appeared so far in the array a[], if not, then the cell at a[i] (number)
        // in the array tempArr will contain the index of a[i] (number).
        if (numPos == -1) {
            tempArr[num] = arrIndex;
            arrIndex++;
        }
        else {
            if (isHandleNumExist) {
                a[arrIndex]++;

                num = a[arrIndex];
                numPos = tempArr[num];

                if (numPos == -1) {
                    // Checks if the new number after adding 1 is not recognized by the tempArr array, if not I update the array
                    tempArr[num] = arrIndex;
                }

                if (arrIndex < numPos) {
                    // Updates the index of the new number after adding 1 to be the initial index that the number exists in the array a[]
                    tempArr[num] = arrIndex;
                }

                cout << "The array at the end:" << endl;
                printArray(a, size);
                cout << endl;
                printArray(tempArr, N);
                cout << endl << endl;

                arrIndex++;
                isHandleNumExist = false;
            }
            else {
                // If the number is already found, meaning the index of the number that already known
                // is equal to the index in the current iteration, then we move to the next cell of the array.
                if (arrIndex == numPos) {
                    arrIndex++;
                }
                else {
                    // Updates the index of the number, meaning the tempArr[num] cell, to be the second index that
                    // the number exists in the array a[], because at the first index that the number exists
                    // I am going to increment the number by 1 using bool called isHandleNumExist.

                    cout << endl << "*** (Num: " << num << ", Pos: " << arrIndex << ") --> (Found also in pos: " << numPos << ") ***" << endl;
                    cout << "The array at the beginning:" << endl;
                    printArray(a, size);
                    cout << endl;
                    printArray(tempArr, N);
                    cout << endl;

                    if ((num == 6) && (arrIndex == 8) && (numPos == 4)) {
                        cout << "?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
                        printArray(tempArr, N);
                        cout << endl << "?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
                    }

                    firstIndexNumExist = tempArr[num];
                    if (arrIndex > numPos) {
                        tempArr[num] = arrIndex;
                    }
                    arrIndex = firstIndexNumExist;
                    isHandleNumExist = true;
                }
            }
        }
        numIteration++;
    }

    return numIteration;
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        if ((a[i] >= 0) && (a[i] < 10)) {
            cout << "   ";
        }
        else {
            cout << "  ";
        }
        cout << a[i];
    }

}
