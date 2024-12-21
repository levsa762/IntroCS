// // Name: Lev Sakaju; ID: 209266667
// // Name: Aviv Raz; ID: 206775959
//
// #include <iostream>
// using namespace std;
//
// int sunNumDigits(int num);
//
// int main() {
//     int num;
//
//     cout << "Please enter a number: " << endl;
//     cin >> num;
//
//     cout << "The sum digits of " << num << " is: " << sunNumDigits(num);
//
//     return 0;
// }
//
// int sunNumDigits(int num) {
//     int sum = 0;
//
//     while (num > 0) {
//         sum += num % 10;
//         num /= 10;
//     }
//
//     return sum;
// }