// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // defines variables
    long num, reverseNum = 0;

    // getting input from user
    cout << "Please enter a number containing 10 digits" << endl;
    cin >> num;

    while (num > 0) {
        reverseNum = (reverseNum * 10) + (num % 10);
        num = num / 10;
    }

    cout << "The reverse number is: " << reverseNum << endl;

    return 0;
}
