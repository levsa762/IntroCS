// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int main(){
    // defines variables
    double plantPrice, plantPriceTotal = 0;
    int plantNum;

    // getting input from user
    cout << "Please enter the plant price" << endl;
    cin >> plantPrice;
    cout << "Please enter the quantity requested" << endl;
    cin >> plantNum;

    if (plantNum > 10) {
        cout << "You have 20% discount." << endl;
        plantPriceTotal = plantPrice * 0.8 * plantNum;
    }
    else if (plantNum > 5) {
        cout << "You have 10% discount." << endl;
        plantPriceTotal = plantPrice * 0.9 * plantNum;
    }
    else {
        plantPriceTotal = plantPrice * plantNum;
    }

    cout << "The total price is: " << plantPriceTotal << endl;

    // Measure memory usage
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "Memory used: " << usage.ru_maxrss << " KB" << std::endl;

    return 0;
}
