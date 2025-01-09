// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

void printDecrypted(char encriptedStr[]);
void reverseString(char str[]);

int main(){
    char str[] = "3y!!roe$&hT+* -gnaB gi#B eh@T";

    printDecrypted(str);
}

void printDecrypted(char encriptedStr[]) {
    int indexStrS = 0, indexStrD = 0;
    char strTemp[strlen(encriptedStr) + 1];

    cout << encriptedStr << endl;
    while (encriptedStr[indexStrS] != '\0') {
        if (encriptedStr[indexStrS] >= '0' && encriptedStr[indexStrS] <= '9') {
            strTemp[indexStrD] = encriptedStr[indexStrS];
            indexStrD++;
        }

        if (encriptedStr[indexStrS] >= 'a' && encriptedStr[indexStrS] <= 'z') {
            strTemp[indexStrD] = encriptedStr[indexStrS];
            indexStrD++;
        }

        if (encriptedStr[indexStrS] >= 'A' && encriptedStr[indexStrS] <= 'Z') {
            strTemp[indexStrD] = encriptedStr[indexStrS];
            indexStrD++;
        }

        indexStrS++;
    }

    strTemp[indexStrD] = '\0';
    reverseString(strTemp);
    cout << strTemp << endl;
}

void reverseString(char str[]) {
    char temp;

    for (int i = 0; i < (strlen(str) - 1) / 2; i++) {
        temp = str[i];
        str[i] = str[strlen(str) - 1 - i];
        str[strlen(str) - 1 - i] = temp;
    }
}
