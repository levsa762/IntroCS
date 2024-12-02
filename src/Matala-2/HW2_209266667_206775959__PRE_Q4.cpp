// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // defines variables
    long num, sumNum = 0;

    // getting input from user
    cout << "Please enter a number" << endl;
    cin >> num;

    while (num > 0) {
        sumNum = sumNum + (num % 10);
        num = num / 10;
    }

    cout << "The sum of digits are: " << sumNum << endl;

    return 0;
}
1