// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>

using namespace std;

#define SIZE 10

#define CASTVALUE 0.27


// function that gets number and finds the largest digit in a number by dividing and compare to max

int maxDigits(int number){
    int digit ;
    int maxDig = 0;
    if(number < 9 && number > 0){
        return number;
    }

    while (number!=0)
    {
        
        digit = number %10;
        if (digit > maxDig)
        {
            maxDig = digit;
        }
        number/=10;
    }
    return maxDig;
}


// function that gets number that equals to nis number(shekel) and convert him to USD with cast value of 0.27 per 1 shekel
double nisToUsd(double number){
    return number*CASTVALUE;
}


// function that gets digit and number - finds if the digit is inside the num
bool isDigInNum(int dig, int num){
    int digitNumber;
    while (num != 0)
    {
     digitNumber = num % 10;
     if(dig == digitNumber){
        return true;
     }
     num /= 10;
    }
    return false;
    
}
// function that gets two numbers and and return new num that contains the shared digits
int sameDigits(int num1, int num2){
    int sharedNum = 0;
    int mul = 1;
    while (num1 != 0)
    {
        if (isDigInNum(num1 % 10 , num2) && !(isDigInNum(num1 % 10, sharedNum)))
        {
            sharedNum = sharedNum + (num1 % 10)*mul;
            mul *= 10;
        }
        num1 /= 10;
    }

    if (sharedNum == 0)
    {
        return -1;
    }
    else{
        return sharedNum;
    }
    
    
    
}

int main(){
    // max digit in a number
    cout << maxDigits(1898) << endl;
    
    // convert nis to usd
    cout << nisToUsd(18) << endl;

    //finds the same digits between two numbers
    cout << sameDigits(12345 ,3265);
}