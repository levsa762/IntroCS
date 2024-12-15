#include <iostream>
using namespace std;

#define SIZE 10

// Function to find the lowest index of a number that appears more than once
int findLowestDuplicateIndex(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return i; // Return the lowest index of the duplicate
            }
        }
    }
    return -1; // No duplicates found
}

// Function to make all array elements unique
int makeArrayUnique(int arr[], int size) {
    int tempArray[SIZE]; // Copy of the original array
    int iterations = 0;  // To count iterations

    // Copy the original array into tempArray
    for (int i = 0; i < size; i++) {
        tempArray[i] = arr[i];
    }

    int duplicateIndex = 0; // Initialize the duplicate index to start the loop
    while (duplicateIndex != -1) {
        // Find the lowest duplicate index
        duplicateIndex = findLowestDuplicateIndex(tempArray, size);

        if (duplicateIndex != -1) {
            // Increment the value at the lowest duplicate index
            tempArray[duplicateIndex]++;
            iterations++; // Increment the iteration count
        }
    }

    // Print the modified array
    cout << "Modified Array: ";
    for (int i = 0; i < size; i++) {
        cout << tempArray[i] << " ";
    }
    cout << endl;

    return iterations; // Return the number of iterations
}

int main() {
    int arry[SIZE] = {1, 3, 4, 5, 6, 5, 3, 17, 6, 10};

    int iterations = makeArrayUnique(arry, SIZE);

    cout << "Total iterations: " << iterations << endl;

    return 0;
}
