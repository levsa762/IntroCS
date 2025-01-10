// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

const int ROWS = 3, SIZE = 100;

int mapSequences(char strMat[][SIZE], int rows);

int main(){
    char arr[ROWS][SIZE] = {"0000000", "10101", "11000001"};

    cout << mapSequences(arr, ROWS) << endl;
}

int mapSequences(char strMat[][SIZE], int rows) {
    int maxSequence = 0, sequence, tempStrIndex;
    char currentChar, tempStr[SIZE];

    for (int i = 0; i < rows; i++) {
        tempStrIndex = 0;
        sequence = 1;
        currentChar = strMat[i][0];

        if (strMat[i][0] != '1') {
            tempStr[tempStrIndex] = '0';
            tempStrIndex++;
        }

        for (int j = 1; strMat[i][j] != '\0' ; j++) {
            if (strMat[i][j] == currentChar) {
                sequence++;
            }
            else {
                tempStr[tempStrIndex] = sequence + '0';
                tempStrIndex++;

                if (sequence > maxSequence) {
                    maxSequence = sequence;
                }

                currentChar = strMat[i][j];
                sequence = 1;
            }
        }

        tempStr[tempStrIndex] = sequence + '0';
        tempStrIndex++;
        tempStr[tempStrIndex] = '\0';
        cout << tempStr << endl;
    }

    return maxSequence;
}
