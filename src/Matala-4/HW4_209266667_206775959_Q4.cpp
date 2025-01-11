#include <iostream>
#include <string.h> 
using namespace std;


// function that takes string, reverse it !

void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}


void printDecrypted(char encriptedStr[]) {
    int lengthStr = strlen(encriptedStr);
    int indexTemp = 0;

    // Extract alphabetic characters only and reverse in place
    for (int i = 0; i < lengthStr; i++) {
        if ((encriptedStr[i] >= 'A' && encriptedStr[i] <= 'Z') || (encriptedStr[i] >= 'a' && encriptedStr[i] <= 'z') || encriptedStr[i] >= '0' && encriptedStr[i] <= '9') {
            encriptedStr[indexTemp] = encriptedStr[i];
            indexTemp++;
        }
    }
    encriptedStr[indexTemp] = '\0';  // end the string when needed

    // Reverse the string in place
    reverseString(encriptedStr);

    cout << encriptedStr;
}

int main() {
    char c[50] = " 03y!!roe$&hT+* -regnaB gi#B eh@%^T tseb45";
    printDecrypted(c);
    cout << endl;
    return 0;
}
