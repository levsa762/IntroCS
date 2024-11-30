// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
       // define vars
       int number;
       int result =1;
       int count = 0;
       int counterTimesOfRnumber = 0;
       int maxAzeret = 2;


       cout << "Enter number bigger than 2" << endl;
       cin >> number;
       if(number<2){
              cout << "You enter number smaller than 2" << endl;
       }
       else{
              // looping through the number and check if the number can be divided more than 2 times if it does it is not prime number
              for (int i = 2; i <= number; i++)
              {
                     count = 0;
                     for (int j = 1 ; j <= i; j++)
                     {
                            if ( i % j == 0)
                            {
                                   count++;
                            }
                            
                     }
                     // check the count of number dividers , if two it is prime and count of how many primes is up by 1
                     if (count == 2)
                     {
                            counterTimesOfRnumber++;
                            cout <<  i << " is prime number" << endl;
                            if(i > maxAzeret){
                                   maxAzeret = i;
                            }
                            
                     }   
                     else{
                            cout << i << " is not a prime number" << endl;
                     } 
              }
              // calculating ! for max prime number
              for (int i = 1; i <= maxAzeret; i++)
              {
                     result*=i;
              }

              cout << "Total prime numbers between 2 and " << number << " is " << counterTimesOfRnumber << endl;
              cout << maxAzeret << "! is " << result;
              
              
       }

}
