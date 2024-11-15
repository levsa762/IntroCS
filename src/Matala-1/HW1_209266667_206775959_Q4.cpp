// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // define consts
    const float cab_starting_price = 12.3;
    const float price_for_one_km = 2.70;
    const float price_for_one_bag = 5.00;

    // define variables for input
    float path_in_km, number_of_bags, total_price;

    // getting input from user
    cout << "Please enter how long is your path in KM" << endl;
    cin >> path_in_km;
    cout << "Please enter how many bags do you have" << endl;
    cin >> number_of_bags;

    // calculate the total price according to the conditions.
    total_price = cab_starting_price + path_in_km * price_for_one_km + number_of_bags * price_for_one_bag;

    // printing the results in NIS
    cout << "The total price for taxi is: " << total_price << " NIS";

    return 0;
}
