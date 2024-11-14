#include <iostream>

using namespace std;

int main(){
    
    //define vars
    char hundreds;
    char tens;
    char units;
    int number;

    // getting input from user
    cout << "enter a single digit number" << endl;
    cin >> hundreds;
    cout << "enter a single digit number" << endl;
    cin >> tens;
    cout << "enter a single digit number" << endl;
    cin >> units;

    // calculating the number
    number = (hundreds - '0')*100 + (tens - '0')*10 + (units - '0');

    //printing the number
    cout << "this is " << number;

    return 0;
}