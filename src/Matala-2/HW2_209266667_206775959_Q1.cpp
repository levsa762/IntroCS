// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // defines variables
    const int ONE_MIN_IN_SECONDS = 60 ,ONE_HOUR_IN_SECONDS = 3600;
    int optionNum;

    // getting input from user
    cout << "Welcome to the conversion program." << endl;
    cout << "Please select a valid option to convert, press any other key to end the program." << endl;
    cout << "Press 1 to convert celcius to fahrenheit" << endl;
    cout << "Press 2 to convert fahrenheit to celcius" << endl;
    cout << "Press 3 to convert seconds to hours, minutes and seconds" << endl;
    cout << "Press 4 to convert hours, minutes and seconds to seconds" << endl;
    cout << "Press 5 to convert decimal number to binary number" << endl;
    cout << "Press 6 to convert binary number to decimal number" << endl;
    cout << "Press 7 to convert characters to a number" << endl;
    cin >> optionNum;

    while ((optionNum >= 1) && (optionNum <= 7)) {
        if (optionNum == 1) {
            float cNum, fNum;

            cout << "Please enter a celcius number" << endl;
            cin >> cNum;

            fNum = cNum * 9 / 5 + 32;
            cout << "The fahrenheit number is: " << fNum << endl;
        }
        else if (optionNum == 2) {
            float fNum, cNum;

            cout << "Please enter a fahrenheit number" << endl;
            cin >> fNum;

            cNum = (fNum - 32) * 5 / 9;
            cout << "The celcius number is: " << cNum << endl;
        }
        else if (optionNum == 3) {
            int seconds, calSeconds, calMinutes, calHours;

            cout << "Please enter seconds number" << endl;
            cin >> seconds;

            calHours = seconds / ONE_HOUR_IN_SECONDS;
            calMinutes = (seconds % ONE_HOUR_IN_SECONDS) / ONE_MIN_IN_SECONDS;
            calSeconds = (seconds % ONE_HOUR_IN_SECONDS) % ONE_MIN_IN_SECONDS;
            cout << "Calculate hours is: " << calHours << endl;
            cout << "Calculate minutes is: " << calMinutes << endl;
            cout << "Calculate seconds is: " << calSeconds << endl;
        }
        else if (optionNum == 4) {
            int calSeconds, seconds, minutes, hours;

            cout << "Please enter hours number" << endl;
            cin >> hours;
            cout << "Please enter minutes number" << endl;
            cin >> minutes;
            cout << "Please enter seconds number" << endl;
            cin >> seconds;

            calSeconds = (hours * ONE_HOUR_IN_SECONDS) + (minutes * ONE_MIN_IN_SECONDS) + seconds;
            cout << "Calculate seconds is: " << calSeconds << endl;
        }
        else if (optionNum == 5) {
            int decimalNum, binaryNum = 0, place = 1;
            cout << "Please enter decimal number" << endl;
            cin >> decimalNum;

            while (decimalNum > 0) {
                int remainder = decimalNum % 2;
                binaryNum = binaryNum + remainder * place;
                decimalNum /= 2;
                place *= 10;
            }

            cout << "The binary number is: " << binaryNum << endl;
        }
        else if (optionNum == 6) {
            int binaryNum, decimalNum = 0, exponent = 0;
            cout << "Please enter binary number" << endl;
            cin >> binaryNum;

            while (binaryNum > 0) {
                // ReSharper disable once CppVariableCanBeMadeConstexpr
                const int BASE_Power = 2;
                int remainder = binaryNum % 10, resultPower = 1;

                for (int i = 0; i < exponent; i++) {
                    resultPower *= BASE_Power;
                }

                decimalNum = decimalNum + remainder * resultPower;
                binaryNum /= 10;
                exponent++;
            }

            cout << "The decimal number is: " << decimalNum << endl;
        }
        else if (optionNum == 7) {
            char character;
            int num = 0, reverseNum = 0;

            cout << "Please enter a character between '0' - '9'" << endl;
            cin >> character;

            while ((character != 'e') && (character != 'E')) {
                num = num * 10 + (character - '0');

                cout << "Please enter a character between '0' - '9'" << endl;
                cin >> character;
            }

             while (num > 0) {
                 reverseNum = reverseNum * 10 + (num % 10);
                 num /= 10;
             }

            cout << "The reverse number is: " << reverseNum << endl;
        }

        // getting input from user
        cout << "Please enter a number" << endl;
        cin >> optionNum;
    }

    return 0;
}
