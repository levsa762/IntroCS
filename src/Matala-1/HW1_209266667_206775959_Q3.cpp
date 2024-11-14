#include <iostream>

using namespace std;

int main(){

    // Initialize variables
    int num;
    int hundreds;
    int tens;
    int units;
    int sum;

    //getting input from user
    cout << "Please enter three digit number" << endl;
    cin >> num;

    // get the hundreds, tens and units
    hundreds = num / 100;
    tens = (num / 10) % 10;
    units =(num % 100) % 10;

    // do sum of all digits
    sum = hundreds + tens + units;

    // reverse the number
    num = units*100 + tens*10 + hundreds;

    //printing results
    cout << "The reversed number is " << num << endl;
    cout << "The sum of the digits is " << sum;
    
    return 0;
}