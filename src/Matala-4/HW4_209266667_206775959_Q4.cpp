#include <iostream>
#include <cstring> 
using namespace std;


// function that takes string, reverse it to temp string and then copy to original

void reverseString(char str[]) {
    int len = strlen(str);
    char temp[len + 1];  
    int index = 0;
    for (int i = len - 1; i >= 0; i--, index++) {
        temp[index] = str[i];
    }
    temp[index] = '\0';   // end the string when needed
    strcpy(str, temp);  // Copy the reversed string back to the original
}


void printDecrypted(char encriptedStr[]) {
    int lengthStr = strlen(encriptedStr);
    char temp[lengthStr + 1];  // +1 for the end ('\0')
    int indexTemp = 0;
    bool islastLetter = false;

    // Extract alphabetic characters only 
    for (int i = 0; i < lengthStr; i++) {
        if ((encriptedStr[i] >= 'A' && encriptedStr[i] <= 'Z') || (encriptedStr[i] >= 'a' && encriptedStr[i] <= 'z') || encriptedStr[i] >='0' && encriptedStr[i] <='9') {
            temp[indexTemp] = encriptedStr[i];
            indexTemp++;
        }
    }
    temp[indexTemp] = '\0';  // end the string when needed
    reverseString(temp); // reverse the string
    cout << temp;
}

int main() {
    char c[50] = " 03y!!roe$&hT+* -regnaB gi#B eh@%^T tseb";
    printDecrypted(c);
    cout << endl;
    return 0;
}
