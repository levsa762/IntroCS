// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

void printMenu();
void excecuteProgram(int num);
int power(int x, int y);
int Sum(int num1, int num2);
int countDigitOfNum(int num);
void printReverseNum(int num);
void printRightAngledTriangle(int n);
void printAscendingOfNum(int n, int digit);
void printDescendingOfNum(int n, int digit);
void printIsoscelesTriangle(int n);
void printSpaceByNum(int n);
int maxSeqInNum(int num);
int maxSeqOfDigitInNum(int num, int digit, int currentCount, int maxCount);

int main()
{
    int num;

    printMenu();
    cin >> num;
    excecuteProgram(num);

    return 0;
}

// This function executes the chosen program based on the user's input number.
void excecuteProgram(int num) {
    int num1, num2;

    // Switch statement to handle function execution based on user input.
    switch (num)
    {
        case 1:
            cout << "Executing power function" << endl;
            cout << "Please enter two numbers" << endl;
            cin >> num1;
            cin >> num2;
            cout << "The result is: " << power(num1, num2) << endl << endl;
            break;
        case 2:
            cout << "Executing Sum function" << endl;
            cout << "Please enter two numbers" << endl;
            cin >> num1;
            cin >> num2;
            cout << "The result is: " << Sum(num1, num2) << endl << endl;
            break;
        case 3:
            cout << "Executing countDigitOfNum function" << endl;
            cout << "Please enter a number" << endl;
            cin >> num1;
            cout << "The result is: " << countDigitOfNum(num1) << endl << endl;
            break;
        case 4:
            cout << "Executing printReverseNum function" << endl;
            cout << "Please enter a number" << endl;
            cin >> num1;
            printReverseNum(num1);
            cout << endl << endl;
            break;
        case 5:
            cout << "Executing printRightAngledTriangle function" << endl;
            cout << "Please enter a number" << endl;
            cin >> num1;
            printRightAngledTriangle(num1);
            cout << endl << endl;
            break;
        case 6:
            cout << "Executing printIsoscelesTriangle function" << endl;
            cout << "Please enter a number" << endl;
            cin >> num1;
            printIsoscelesTriangle(num1);
            cout << endl << endl;
            break;
        case 7:
            cout << "Executing maxSeqInNum function" << endl;
            cout << "Please enter a number" << endl;
            cin >> num1;
            cout << maxSeqInNum(num1) << endl << endl;
            break;
        case 8:
            cout << "GoodBye!";
            return;
        default:
            cout << "You entered an incorrect number" << endl;
            break;
    }

    printMenu();
    cin >> num;
    excecuteProgram(num);
}

void printMenu() {
    cout << "Please enter a number between 1-8 to execute a function" << endl;
    cout << "1: power" << endl << "2: Sum" << endl;
    cout << "3: countDigitOfNum" << endl << "4: printReverseNum" << endl;
    cout << "5: printRightAngledTriangle" << endl << "6: printIsoscelesTriangle" << endl;
    cout << "7: maxSeqInNum" << endl << "8: Exit from the program" << endl;
}

// Recursive function to calculate power (x^y).
int power(int x, int y) {
    if (y == 0) {
        return 1; // Base case for power: any number to the power of 0 is 1.
    }

    return x * power(x, y - 1);
}

// Recursive function to calculate the sum of numbers from num1 to num2.
int Sum(int num1, int num2) {
    if (num1 > num2) {
        return 0; // Base case: stop when num1 exceeds num2.
    }

    return num1 + Sum(num1 + 1, num2);
}

// Recursive function to count the digits in a number.
int countDigitOfNum(int num) {
    if (num == 0) {
        return 0; // Base case: if the number is 0, no digits to count.
    }

    return 1 + countDigitOfNum(num / 10);
}

// Recursive function to print the reverse of a number.
void printReverseNum(int num) {
    int digit;

    if (num == 0) {
        return;
    }

    digit = num % 10; // Get the last digit.
    cout << digit; // Print the last digit.
    printReverseNum(num / 10);
}

// Recursive function to print a right-angled triangle.
void printRightAngledTriangle(int n) {
    if (n == 0) {
        return; // Base case: stop when n reaches 0.
    }

    printRightAngledTriangle(n - 1); // Recurse to print previous rows.
    printAscendingOfNum(n, 1); // Print numbers in ascending order.
    printDescendingOfNum(n - 1, 1); // Print numbers in descending order.
    cout << endl;
}

// Recursive function to print numbers in ascending order.
void printAscendingOfNum(int n, int digit) {
    if (n == 0) {
        return;
    }

    cout << digit; // Print the current digit.
    printAscendingOfNum(n - 1, digit + 1); // Recurse for the next digit.
}

// Recursive function to print numbers in descending order.
void printDescendingOfNum(int n, int digit) {
    if (n == 0) {
        return;
    }

    printDescendingOfNum(n - 1, digit + 1); // Recurse for the next digit.
    cout << digit; // Print the current digit.
}

void printIsoscelesTriangle(int n) {
    if (n == 0) {
        return;
    }

    static int maxN = n;  // Keep track of the initial value of n to calculate spaces

    printIsoscelesTriangle(n - 1);  // Recursively print the upper rows of the triangle
    printSpaceByNum(maxN - n);  // Print the leading spaces for the current row
    printAscendingOfNum(n, 1);  // Print ascending numbers for the current row
    printDescendingOfNum(n - 1, 1);  // Print descending numbers after the ascending part
    cout << endl;  // Move to the next line after printing the current row
}

void printSpaceByNum(int n) {
    if (n == 0) {
        return;
    }

    cout << " ";
    printSpaceByNum(n - 1);
}

int maxSeqInNum(int num) {
    int digit, currentCount, lastCount, maxCount;

    if (num == 0) {
        return 0;  // Base case: If num is 0, there are no sequences
    }

    digit = num % 10;  // Get the last digit of the number
    currentCount = maxSeqOfDigitInNum(num, digit, 0, 0);  // Count the max sequence of the current digit
    lastCount = maxSeqInNum(num / 10);  // Recursively find the max sequence for the remaining digits

    if (lastCount > currentCount) {
        maxCount = lastCount; // Not necessary variable - Just for clear code.
    }
    else {
        maxCount = currentCount; // Not necessary variable - Just for clear code.
    }

    return maxCount;
}

int maxSeqOfDigitInNum(int num, int digit, int currentCount, int maxCount) {
    if (num == 0) {
        return (currentCount > maxCount) ? currentCount : maxCount;  // Base case: Return the max count when num reaches 0
    }

    int currectDigit = num % 10;  // Get the last digit of the number

    if (currectDigit == digit) {
        return maxSeqOfDigitInNum(num / 10, digit, currentCount + 1, maxCount);  // If digit matches, increment the count
    }
    else {
        return maxSeqOfDigitInNum(num / 10, digit, 0, (currentCount > maxCount) ? currentCount : maxCount);  // If digit doesn't match, reset the count
    }
}
