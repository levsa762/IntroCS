// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>

#define LASTCHOICE 8

using namespace std;

int pow(int x, int y){
    if (y==0)
    {
        return 1;
    }

    return x * pow(x, y-1);
}

int Sum(int num1, int num2){
    if (num2 < num1)
    {
        return 0;
    }

    return num2 + Sum(num1,num2-1);
}

void printMenu(){
        int choice;
        do {
        cout << endl;
        cout << "Choose a number from 1 to 8 to launch function: " << endl;
        cout << "1. Calculate a number in power of other number " << endl << "2. Returns the sum of all numbers between 1num and 2num inclusive." << endl;
        cout << "3. Returns the number of digits in a number" << endl << "4. Prints reverse of given number "  << endl << "5. Prints for an integer n a right triangle consisting of ascending and descending numbers from 1 to n" << endl;
        cout << "6. Prints for an integer n an isosceles triangle consisting of ascending and descending numbers from 1 to n " << endl << "7. Returns the length of the longest sequence of digits in num." << endl;
        cout << "8. GoodBye !" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << " Enter a number and number to power " << endl;
            int x;
            int y;
            cin >> x;
            cin >> y ;
            cout << endl;
            cout << x << " power of "<< y << " is " << pow(x,y) << endl;
            break;
        case 2:
            cout << " Enter 2 numbers " << endl;
            int num1;
            int num2;
            cin >> num1;
            cin >> num2;
            cout << endl;
            cout << "The reults : "<< Sum(num1,num2) << endl;
            
        
        default:
            break;
        }
        } while (choice!=LASTCHOICE) ;
}

int main(){
        printMenu();
}
