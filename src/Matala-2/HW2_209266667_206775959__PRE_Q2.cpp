// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // defines variables
    int yearNum;

    // getting input from user
    cout << "Please enter year (for example 1998)" << endl;
    cin >> yearNum;

    if ((yearNum % 19 == 0) || (yearNum % 19 == 3) || (yearNum % 19 == 6) || (yearNum % 19 == 8) || (yearNum % 19 == 11) || (yearNum % 19 == 14) || (yearNum % 19 == 17)) {
        cout << "A Leap Year";
    }
    else {
        cout << "Not a Leap Year";
    }

    return 0;
}
