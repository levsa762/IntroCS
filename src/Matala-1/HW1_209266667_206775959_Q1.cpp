// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // define consts
    int birthYear, idNumber, height, age;
    char gender;
    const int CURRENT_YEAR =  2024;

    // getting input from user
    cout << "Please enter your birth year" << endl;
    cin >> birthYear;
    cout << "Please enter your id number" << endl;
    cin >> idNumber;
    cout << "Please enter your height in cm " << endl;
    cin >> height;
    cout << "Please enter your gender (M or F)" << endl;
    cin >> gender;

    // calculate age
    age = CURRENT_YEAR - birthYear;

    // printing results
    cout << "You are " << age << " years old and your id number is " << idNumber << endl;
    cout << "Your height is " << height << " cm and your gender is " << gender;

    return 0;
}
