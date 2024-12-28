// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>
using namespace std;
#define SIZE 3
#define COL 100

int mapSequences(char strMat[][COL], int rows) {
    int maxSequences = 0; 

    for (int i = 0; i < rows; i++) {
        char tempArray[COL] = {}; // Temporary array to store sequence counts
        int indexTemp = 0;       // Index for the temporary array
        int count = 0;           // Counter for the current sequence

        // Check if the row starts with '1', otherwise add '0' to the sequence array
        if (strMat[i][0] != '1') {
            tempArray[indexTemp] = '0';
            indexTemp++;
        }

        for (int j = 0; strMat[i][j] != '\0'; j++) {
            if (j == 0 || strMat[i][j] == strMat[i][j - 1]) {
                count++; // Increment the count for the current sequence
            } else {
                // Add the count of the previous sequence to the array
                tempArray[indexTemp] = count + '0';
                indexTemp++;
                count = 1; // Reset the count for the new sequence
            }
        }

        // Add the last sequence count to the array
        tempArray[indexTemp] = count + '0';
        indexTemp++;
        tempArray[indexTemp] = '\0'; 

        // Print the sequence array for the current row
        cout << tempArray << endl;

        // Update the maximum sequence count if necessary
        if (indexTemp > maxSequences) {
            maxSequences = indexTemp;
        }
    }

    return maxSequences; // Return the maximum sequence count
}

int main() {
    char co[SIZE][COL] = {"0000000", "10101", "11000001"};

    // Call the function and print the maximum number of sequences
    int maxSequences = mapSequences(co, SIZE);
    cout << "Maximum sequences: " << maxSequences << endl;

    return 0;
}
