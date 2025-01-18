// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>

#define LASTCHOICE 8

using namespace std;

void printMenu(){
        int choice;
        do {
        cout << "Choose a number from 1 to 8 to launch function: " << endl;
        cout << "1. Calculate a number in power of other number " << endl << "2. Returns the sum of all numbers between 1num and 2num inclusive." << endl;
        cout << "3. Returns the number of digits in a number" << endl << "4. Prints reverse of given number "  << endl << "5. Prints for an integer n a right triangle consisting of ascending and descending numbers from 1 to n" << endl;
        cout << "6. Prints for an integer n an isosceles triangle consisting of ascending and descending numbers from 1 to n " << endl << "7. Returns the length of the longest sequence of digits in num." << endl;
        cout << "8. GoodBye !" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            break;
        
        default:
            break;
        }
        } while (choice!=LASTCHOICE) ;
}

int main(){



        printMenu();
}
