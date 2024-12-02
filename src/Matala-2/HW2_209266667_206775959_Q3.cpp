// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // defines variables
    int num, tempNum, numWithOutLastDigit, numWithOutLastDigitPlace, newNum = 0, newNumPlace = 1, lastDigitNum, lastDigitTempNum;

    // getting input from user
    cout << "Please enter a number" << endl;
    cin >> num;

    while (num > 0) {
        numWithOutLastDigitPlace = 1;
        numWithOutLastDigit = 0;
        lastDigitNum = num % 10;
        num = num / 10;
        tempNum = num;
        while (tempNum > 0) {
            lastDigitTempNum = tempNum % 10;
            if (lastDigitTempNum != lastDigitNum) {
                numWithOutLastDigit = numWithOutLastDigit + numWithOutLastDigitPlace * lastDigitTempNum;
                numWithOutLastDigitPlace *= 10;
            }
            tempNum = tempNum / 10;
        }
        newNum = newNum + newNumPlace * lastDigitNum;
        newNumPlace *= 10;
        num = numWithOutLastDigit;
    }
    cout << "Num is: " << newNum << endl;

    return 0;
}
