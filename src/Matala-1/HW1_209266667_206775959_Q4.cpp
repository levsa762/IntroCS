// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // define consts
    const float CAB_STARTING_PRICE = 12.3;
    const float PRICE_FOR_ONE_KM = 2.70;
    const float PRICE_FOR_ONE_BAG = 5.00;

    // define variables for input
    float pathInKm, numberOfBags, totalPrice;

    // getting input from user
    cout << "Please enter how long is your path in KM" << endl;
    cin >> pathInKm;
    cout << "Please enter how many bags do you have" << endl;
    cin >> numberOfBags;

    // calculate the total price according to the conditions.
    totalPrice = CAB_STARTING_PRICE + pathInKm * PRICE_FOR_ONE_KM + numberOfBags * PRICE_FOR_ONE_BAG;

    // printing the results in NIS
    cout << "The total price for taxi is: " << totalPrice << " NIS";

    return 0;
}
