// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // defines variables
    int num, maxPrimeNum, totalPrimeNum = 0, totalNumAteret = 1;
    bool isPrime;

    // getting input from user
    cout << "Please enter a number" << endl;
    cin >> num;

    // go through all the numbers between 2 and the number entered by the user
    if (num >= 2) {
        for (int i = 2; i <= num; i++) {
            // now we are checking if 'i' is a prime or not
            isPrime = true;
            for (int j = 2; (j <= (i / 2)) && isPrime; j++) {
                if ((i % j) == 0) {
                    isPrime = false;
                }
            }

            if (isPrime) {
                cout << "The number " << i << " is a prime number" << endl;
                maxPrimeNum = i;
                totalPrimeNum++;
            }
            else {
                cout << "The number " << i << " is not a prime number" << endl;
            }
        }
        cout << "Total prime numbers between 2 and " << num << " is: " << totalPrimeNum << endl;

        for (int i=1; i <= maxPrimeNum; i++) {
            totalNumAteret = totalNumAteret * i;
        }
        cout << "Ateret of " << maxPrimeNum << " is: " << totalNumAteret << endl;
    }
    else {
        cout << "The number is less than 2" << endl;
    }

    return 0;
}
