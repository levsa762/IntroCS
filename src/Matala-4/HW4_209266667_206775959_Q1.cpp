// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>

using namespace std;

#define N 3



/* In this method it acts like the 2d array is normal array and does bubble sort, it does like the regular bubble sort -  j+1 > j ,
 but the second line first value compared with the last one in first row and on...
*/
void bubbleSort2D(int n, int arr[][N]) {
    int totalElementsInArray = n * n;
    int row1;
    int col1;
    int col2;
    int row2;
    int temp ;

    // Perform Bubble Sort
    for (int i = 0; i < totalElementsInArray - 1; i++) {
        for (int j = 0; j < totalElementsInArray - i - 1; j++) {
            row1 = j / n;
            col1 = j % n;

            row2 = (j + 1) / n;
            col2 = (j + 1) % n;

            // Compare and manually swap if necessary
            if (arr[row1][col1] > arr[row2][col2]) {
                temp = arr[row1][col1];
                arr[row1][col1] = arr[row2][col2];
                arr[row2][col2] = temp;
            }
        }
    }
}

// Function to print the 2D array
void print2DArray(int n, int arr[][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int arr[N][N];

    // Input the 3x3 array
    cout << "Enter elements of the 3x3 array:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j] ;
            cout << " ";
        }
    }


    cout << "Original 2D array:" << endl;
    print2DArray(N, arr);

    // Sort the array
    bubbleSort2D(N, arr);

    cout << "Sorted 2D array:" << endl;
    print2DArray(N, arr);

    return 0;
}

    
