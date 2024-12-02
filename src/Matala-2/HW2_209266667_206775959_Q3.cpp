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

    // looping until num is less than zero
    while (num > 0) {
        // remove last digit of num
        numWithOutLastDigitPlace = 1;
        numWithOutLastDigit = 0;
        lastDigitNum = num % 10;
        num = num / 10;
        tempNum = num;
        // looping until temp num is less than zero
        while (tempNum > 0) {
            lastDigitTempNum = tempNum % 10;
            if (lastDigitTempNum != lastDigitNum) {
                // create new num without last digit
                numWithOutLastDigit = numWithOutLastDigit + numWithOutLastDigitPlace * lastDigitTempNum;
                numWithOutLastDigitPlace *= 10;
            }
            tempNum = tempNum / 10;
        }
        // create new num without repetition of digits
        newNum = newNum + newNumPlace * lastDigitNum;
        newNumPlace *= 10;
        // change the value of num variable to hold numbers with digits that equal to last digit
        num = numWithOutLastDigit;
    }
    cout << "newNum: " << newNum << endl;

    return 0;
}
