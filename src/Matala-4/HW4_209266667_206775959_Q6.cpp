// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

const int ROWS = 3, SIZE = 100;

int mapSequences(char strMat[][SIZE], int rows);

int main(){
    char arr[ROWS][SIZE] = {"0000000", "10101", "11000001"};

    // Call the function and print the maximum number of sequences
    cout << mapSequences(arr, ROWS) << endl;
}

int mapSequences(char strMat[][SIZE], int rows) {
    int maxSequence = 0, sequence, tempStrIndex;
    char currentChar, tempStr[SIZE];

    for (int i = 0; i < rows; i++) {
        tempStrIndex = 0;
        sequence = 1;
        currentChar = strMat[i][0];

        if (strMat[i][0] != '0' && strMat[i][0]!= '1') {
            cout << "You can not put non binary number, please fix it";
            return -1;
        }

        // Check if the row starts with '1', otherwise add '0' to the sequence array
        if (strMat[i][0] != '1') {
            tempStr[tempStrIndex] = '0';
            tempStrIndex++;
        }

        for (int j = 1; strMat[i][j] != '\0' ; j++) {
            if (strMat[i][j] != '0' && strMat[i][j]!= '1') {
                cout << "You can not put non binary number, please fix it";
                return -1;
            }

            if (strMat[i][j] == currentChar) {
                sequence++; // Increment the count for the current sequence
            }
            else {
                // Add the count of the previous sequence to the array
                tempStr[tempStrIndex] = sequence + '0';
                tempStrIndex++;

                // Update the maximum sequence count if necessary
                if (sequence > maxSequence) {
                    maxSequence = sequence;
                }

                currentChar = strMat[i][j];
                sequence = 1; // Reset the count for the new sequence
            }
        }

        // Add the last sequence count to the array
        tempStr[tempStrIndex] = sequence + '0';
        tempStrIndex++;
        tempStr[tempStrIndex] = '\0';

        // Print the sequence array for the current rows
        cout << tempStr << endl;
    }

    // Return the maximum sequence count
    return maxSequence;
}