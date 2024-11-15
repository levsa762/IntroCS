// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // define vars
    char hundreds, tens, units;
    int number;

    // getting input from user
    cout << "Enter a single digit number" << endl;
    cin >> hundreds;
    cout << "Enter a single digit number" << endl;
    cin >> tens;
    cout << "Enter a single digit number" << endl;
    cin >> units;

    // calculating the number
    number = (hundreds - '0') * 100 + (tens - '0') * 10 + (units - '0');

    // printing the number
    cout << "The number is: " << number;

    return 0;
}
