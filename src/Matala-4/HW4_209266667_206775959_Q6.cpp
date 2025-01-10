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
    int maxSequence = 0, sequence, tempArrIndex;
    char currentChar, tempArr[ROWS][SIZE] = {0};

    for (int i = 0; i < rows; i++) {
        tempArrIndex = 0;
        sequence = 1;
        currentChar = strMat[i][0];

        if (strMat[i][0] != '1') {
            tempArr[i][tempArrIndex] = '0';
            tempArrIndex++;
        }

        for (int j = 1; strMat[i][j] != '\0' ; j++) {
            if (strMat[i][j] == currentChar) {
                sequence++;
            }
            else {
                tempArr[i][tempArrIndex] = sequence + '0';
                tempArrIndex++;

                if (sequence > maxSequence) {
                    maxSequence = sequence;
                }

                currentChar = strMat[i][j];
                sequence = 1;
            }
        }

        tempArr[i][tempArrIndex] = sequence + '0';
        tempArrIndex++;
        tempArr[i][tempArrIndex] = '\0';
        cout << tempArr[i] << endl;
    }

    return maxSequence;
}
