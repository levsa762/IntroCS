// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // define consts
    int birthYear, idNumber, height, age;
    char gender;
    string gender_string;
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

    // checking gender and init his string
    if (gender == 'M'){
        gender_string = "Male";
    }
    else if (gender ==  'F'){
        gender_string = "Female" ;
    }
    else{
        cout << "You entered wrong char";
        return 1;
    }

    // calculate age
    age = CURRENT_YEAR - birthYear;

    // printing results
    cout << "You are " << age << " years old and your id number is " << idNumber << endl;
    cout << "Your height is " << height << " cm and your gender is " << gender_string;

    return 0;
}
