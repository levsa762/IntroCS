#include <iostream> 

using namespace std;

int main(){
    //define consts
    int birth_year;
    int id_number;
    int height;
    char gender;
    string gender_string;
    int age;
    const int current_year =  2024;
    

    // getting input from user
    cout << "Please enter your birth year" << endl;
    cin >> birth_year;
    cout << "Please enter your id number" << endl;
    cin >> id_number;
    cout << "Please enter your height in cm " << endl;
    cin >> height;
    cout << "Please enter your gender" << endl;
    cin >> gender;

    // checking gender and init his string
    if (gender == 'M')
    {
        gender_string = "Male";
    }
    else if (gender ==  'F')
    {
        gender_string = "Female" ;
    }
    else{
        gender_string = "you entered wrong char";
    }
    
    // calculate age
    age = current_year - birth_year;

    //printing results
    cout << "You are " << age << " years old and your id number is " << id_number << endl << "your height is " << height << " cm and your gender is " << gender_string; 

    return 0;
}