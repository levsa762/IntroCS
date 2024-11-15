//
// Created by Aviv Raz on 13/11/2024.
//

#include <iostream>
using namespace std;

int birthYear, id, height;
int currentYear = 2024;
char gender;

int main()
{
    cout << "Your birthday year is: ";
    cin >> birthYear;
    cout << "Your ID is: ";
    cin >> id;
    cout << "Your height is: ";
    cin >> height;
    cout << "Your gender is (F or M): ";
    cin >> gender;

    cout << "Your age is: " << (currentYear - birthYear) << endl;
    cout << "Your ID is: " << id << endl;
    cout << "Your height is: " << height << endl;
    cout << "Your gender is: " << gender;
    return 0;
}
