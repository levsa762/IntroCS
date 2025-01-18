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

int countDig(int num){
    if (num == 0)
    {
        return 0;
    }
    return 1 + countDig(num/10);
}

void reversedPrint(int num){
    if (num == 0)
    {
        return;
    }
    cout << num %10;
    return reversedPrint(num / 10);
}

///////////////////////////////////

void printIncreasing(int n) {
    if (n == 0){
        return;
    } 
    printIncreasing(n - 1);
    cout << n;
}

void printDecreasing(int n) {
    if (n == 0){
        return;
    } 
    cout << n;
    printDecreasing(n - 1);
}

void printPatternUptoDown(int n) {
    if (n == 0){
        return;
    } 
    printPatternUptoDown(n - 1);
    printIncreasing(n);
    printDecreasing(n - 1);
    cout << endl;
}

void printSpace(int num){
    if (num == 0)
    {
        return;
    }
    cout << " "; 
    return printSpace(num -1);
}

void printTreePattren(int n , int max){
    if (n == 0){
        return;
    }
    printTreePattren(n - 1, max);
    printSpace(max- (n-1));
    printIncreasing(n);
    printDecreasing(n - 1);
    cout << endl;
}

void printTree(int n){
    printTreePattren(n,n);
}


int findLongestSequenceHelper(int num, int prevDigit, int currentCount, int maxCount) {
    if (num == 0){
        return maxCount;
    } 

    if (num % 10 == prevDigit) {
        currentCount++;
    } else {
        currentCount = 1;
    }

    if (currentCount > maxCount) {
        maxCount = currentCount;
    }
    return findLongestSequenceHelper(num / 10, num % 10, currentCount, maxCount);
}

int findLongestSequence(int num) {
    if (num == 0){
        return 0;
    }  
    return findLongestSequenceHelper(num / 10, num % 10, num / num, num / num);
}

////////////////////

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
            break;
        case 3:
            cout << " Enter a number " << endl;
            int num;
            cin >> num;
            cout << endl;
            cout << "The count digits : " << countDig(num) << endl;
            break;
        case 4:
            cout << " Enter a number " << endl;
            int revNum;
            cin >> revNum;
            cout << endl;
            cout << "The reversed num is : ";
            reversedPrint(revNum);
            break;
        case 5:
            cout << " Enter a number " << endl;
            int pattNum1;
            cin >> pattNum1;
            cout << endl;
            cout << "The pattern is : " << endl;
            printPatternUptoDown(pattNum1);
            break;
        case 6:
            cout << " Enter a number " << endl;
            int pattNum2;
            cin >> pattNum2;
            cout << endl;
            cout << "The pattern is : " << endl;
            printTree(pattNum2);
            break;
        case 7:
            cout << " Enter a number " << endl;
            int seqNum;
            cin >> seqNum;
            cout << endl;
            cout << "The logest amount of sequence is : " << findLongestSequence(seqNum) << endl;
            break;
        case 8:
            cout << " GoodBye !";
            break;
        default:
            break;
        }
        } while (choice!=LASTCHOICE) ;
}

int main(){
        printMenu();
}
