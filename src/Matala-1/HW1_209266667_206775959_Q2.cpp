#include <iostream>

using namespace std;

int main(){

    char hundreds;
    char tens;
    char units;
    int number;

    cout << "enter a single digit number" << endl;
    cin >> hundreds;
    cout << "enter a single digit number" << endl;
    cin >> tens;
    cout << "enter a single digit number" << endl;
    cin >> units;

    number = (hundreds - '0')*100 + (tens - '0')*10 + (units - '0');
    cout << "this is " << number;

}