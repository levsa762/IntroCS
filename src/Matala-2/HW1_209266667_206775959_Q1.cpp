// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){

        // define variables for all options
        int key = 1;
        float celcius;
        float farenheit;
        int seconds;
        int hours;
        int minutes;
        int number;
        int dig;
        int mult;
        int sum;
        char character;
        while (key >= 1 && key <=7 )
        {
                // Printing Menu
                cout << "Welcome to the Convertion program." << endl << "Please select a valid option to convert , press any other key to end the program."<< endl;
                cout << "Press 1 to convert celcius to farenheit" <<endl << "Press 2 to convert to convert farenheit to celcius " << endl;
                cout << "Press 3 to convert seconds to hours, minutes and seconds" <<endl << "Press 4 to convert hours, minutes and seconds to seconds"<< endl;
                cout << "Press 5 to convert decimal number to binary number" << endl << "Press 6 to convert binary number to decimal number" << endl << "Press 7 to convert charecters to number"<<endl;
                cin >> key;
                switch (key)
                {
                case 1:
                        // input of celcius and calculating to farenheit
                        cout << "Enter a number you wish to convert from celcius to farenheit" << endl;
                        cin >> celcius;
                        farenheit = (celcius*1.8) + 32;
                        cout << "Your number in celcius is " << celcius << " and in farenheit is " << farenheit<<endl;
                        break;
                case 2:
                       // input of farenheit  and calculating to celcius
                        cout << "Enter a number you wish to convert from farenheit  to celcius" << endl;
                        cin >> farenheit;
                        celcius = (farenheit - 32) * 5/9 ;
                        cout << "Your number in franheit is " << farenheit << " and in celcius is " << celcius <<endl;
                        break;
                case 3:
                        // calculating number of hours minutes and seconds from total seconds
                        cout << "Enter number of seconds you wish to convert to hours , minutes and seconds" << endl;
                        cin >> seconds;
                        hours = int(seconds/3600);
                        seconds = seconds - (hours*3600);
                        minutes = int(seconds/60);
                        seconds = seconds - (minutes*60);
                        cout << "Hours:  " << hours << " minutes: "<< minutes << " seconds: " << seconds << endl;  
                        break;
                case 4:
                        // calculating seconds from hours minutes and seconds
                        cout << "Enter number of hours , minutes and seconds  you wish to convert to seconds" << endl;
                        cin >> hours;
                        cin >> minutes;
                        cin >> seconds;
                        cout << "The number of seconds in total is " << (hours * 3600 + minutes*60 + seconds) << endl;
                        break;
                case 5:
                        // casting decimal number into binary
                        cout << "Enter decimal number ";
                        cin >> number;
                        mult = 1;
                        sum = 0;
                        while (number!=0)
                        {
                                dig = number%2;
                                sum += dig * mult;
                                mult*=10;
                                number /= 2;
                        }
                        cout << "The number in decimal is " << sum << endl;
                        
                        break;
                case 6:
                        // casting binary to decimal
                        cout << "Enter binary number ";
                        cin >> number;
                        mult = 1;
                        sum = 0;
                        while (number != 0)
                        {
                                dig = number % 10;
                                sum += dig*mult;
                                mult*=2;
                                number/=10;
                        }
                        cout << "The number in decimal is " << sum << endl;
                        

                        break;
                case 7:
                        // reverse number by chars of input till letter e or E 
                        mult = 1;
                        cout << "Enter numbers and if you wish to stop enter the letter e or E" << endl;
                        bool flag;
                        flag = false;
                        while (!flag)
                        {
                                cin >> character;
                                if(character == 'e' || character == 'E'){
                                        flag = true;
                                }
                                else{
                                        sum += (character - '0')*mult;
                                        mult*=10;
                                        
                                }

                                
                        }
                        cout << "The number is " << sum << endl;
                        
                        
                        break;
                
                default:
                        cout << "Bye Bye"  ;
                }
        }

        return 0;
}
