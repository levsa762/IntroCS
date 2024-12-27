// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream> // For input-output operations
using namespace std;

// Macro defining the size of the array
#define N 5

// Function to perform a reverse Bubble Sort on an array
// The array will be sorted in descending order (largest to smallest)
void reverseBubbleSort(int arr[], int size) {
    int temp; 
    for (int i = 0; i < size - 1; i++) { 
        for (int j = 0; j < size - i - 1; j++) { 
            // If the current element is smaller than the next, swap them
            if (arr[j] < arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* Function to perform a binary search on an array sorted in descending order
 The array is sorted using `reverseBubbleSort` before the search
 Parameters:
 - arr: The array to search in
 - size: The size of the array
 - value: The value to search for
 Returns: 0 if the value is found, 1 otherwise

*/
int bSearch(int arr[], int size, int value) {
    int low = size - 1; // Low index (start from the last index in descending order)
    int high = 0;       // High index (start from the first index)
    int mid = (low + high) / 2; // Midpoint index

    // Sort the array in descending order
    // Since we cannot assume the input array is pre-sorted
    reverseBubbleSort(arr, size);

    // Perform binary search
    while (low >= high) { // Continue until the search space is exhausted
        if (value == arr[mid]) { // Check if the midpoint element matches the target
            cout << value << " found ";
            return 0; // Return success
        }

        // Adjust the search range based on the target value
        if (value > arr[mid]) {
            low = mid - 1; // Search in the lower half
        } else {
            high = mid + 1; // Search in the upper half
        }

        // Recalculate the midpoint for the next iteration
        mid = (low + high) / 2;
    }

    // If the loop completes, the value is not found
    cout << value << " not found";
    return 1; // Return failure
}

int main() {
    // Initialize an array with unsorted elements
    int arr[] = {18, 63, 52, 13, 100};

    // Print the original array
    for (int i = 0; i < N; i++) {
        cout << " " << arr[i];
    }
    cout << endl;

    // Perform a binary search for the value 7 in the array
    // The array will be sorted in descending order before the search
    bSearch(arr, N, 13);

    return 0;
}
