// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

#define USD_IN_NIS 0.27

int maxDigits(int num);
double nisToUsd(double nisAmount);
int sameDigits(int num1, int num2);
int removeRepDigits(int num);
int reverseNumber(int num);

int main() {
    int numForMaxDigit, numForSameDigits1, numForSameDigits2;
    double nisAmount;

    cout << "Please enter a number: " << endl;
    cin >> numForMaxDigit;
    cout << "The max digit of " << numForMaxDigit << " is: " << maxDigits(numForMaxDigit) << endl;
    cout << "Please enter amount of NIS: " << endl;
    cin >> nisAmount;
    cout << "The amount of " << nisAmount << " INS in USD is: " << nisToUsd(nisAmount) << endl;
    cout << "Please enter two numbers: " << endl;
    cin >> numForSameDigits1;
    cin >> numForSameDigits2;
    cout << "The new number that include the same digits from " << numForSameDigits1 << " and " << numForSameDigits2;
    cout << " is: " << sameDigits(numForSameDigits1, numForSameDigits2);

    return 0;
}

int maxDigits(int num) {
    int maxDigit = 0, lastDigit;

    while(num > 0) {
        lastDigit = num % 10;

        if (lastDigit > maxDigit) {
            maxDigit = lastDigit;
        }

        num /= 10;
    }

    return maxDigit;
}

double nisToUsd(double nisAmount) {
    return USD_IN_NIS * nisAmount;
}

int sameDigits(int num1, int num2) {
    int tempNum2, newNum = 0, newNumPlace = 1, lastDigitOfNum1, lastDigitOfTempNum2;

    num1 = removeRepDigits(num1);
    num2 = removeRepDigits(num2);

    while (num1 > 0) {
        lastDigitOfNum1 = num1 % 10;
        tempNum2 = num2;

        while (tempNum2 > 0) {
            lastDigitOfTempNum2 = tempNum2 % 10;

            if (lastDigitOfNum1 == lastDigitOfTempNum2) {
                newNum = newNum + newNumPlace * lastDigitOfNum1;
                newNumPlace *= 10;
            }

            tempNum2 /= 10;
        }

        num1 /= 10;
    }

    return newNum;
}

int removeRepDigits(int num) {
    int tempNewNum, newNum = 0, placeNewNum = 1, lastDigitOfNum, lastDigitOfCopyNewNum;
    bool isDigitFound;

    num = reverseNumber(num);

    while (num > 0) {
        lastDigitOfNum = num % 10;
        tempNewNum = newNum;
        isDigitFound = false;

        while (tempNewNum > 0 && !isDigitFound) {
            lastDigitOfCopyNewNum = tempNewNum % 10;

            if (lastDigitOfNum == lastDigitOfCopyNewNum) {
                isDigitFound = true;
            }

            tempNewNum /= 10;
        }

        if (!isDigitFound) {
            newNum += placeNewNum * lastDigitOfNum;
            placeNewNum *= 10;
        }

        num /= 10;
    }

    newNum = reverseNumber(newNum);
    return newNum;
}

int reverseNumber(int num) {
    int reverseNum = 0, lastDigit;

    while (num > 0) {
        lastDigit = num % 10;
        reverseNum = reverseNum * 10 + lastDigit;
        num /= 10;
    }

    return reverseNum;
}
