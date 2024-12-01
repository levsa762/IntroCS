// // Name: Lev Sakaju; ID: 209266667
// // Name: Aviv Raz; ID: 206775959
//
// #include <iostream>
// using namespace std;
//
// int main(){
//     // defines variables
//     int num, lastDigitNum, tempNum1, tempNum2, placeTempNum2, newNum = 0, placeNewNum = 1, placeNum = 1;
//
//     // getting input from user
//     cout << "Please enter a number" << endl;
//     cin >> num;
//
//     // 1232
//
//     // 2
//     // 123
//
//     while (num / placeNum > 0) {
//         tempNum2 = 0;
//         placeTempNum2 = 1;
//         lastDigitNum = num % 10;
//         tempNum1 = num / 10;
//
//         while (tempNum1 > 0) {
//             if ((tempNum1 % 10) != lastDigitNum) {
//                 tempNum2 = tempNum2 + placeTempNum2 * (tempNum1 % 10);
//                 placeTempNum2 = placeTempNum2 * 10;
//             }
//             tempNum1 = tempNum1 / 10;
//         }
//         newNum = newNum + placeNewNum * lastDigitNum;
//         placeNewNum = placeNewNum * 10;
//         placeNum = placeNum * 10;
//         cout << "newNum is: " << newNum << endl;
//         cout << "placeNum is: " << placeNum << endl;
//         cout << "placeNewNum is: " << placeNewNum << endl;
//         cout << "tempNum2 is: " << tempNum2 << endl;
//
//         num = tempNum2;
//     }
//     newNum = newNum * 10 + num;
//     cout << "The lastDigitNum is: " << lastDigitNum << endl;
//     cout << "The newNum is: " << newNum << endl;
//
//     return 0;
// }
//
// // num = 12322
// // place = 1
// //
// //
// // digit = ((num / place) % 10) --> digit = 2
// // num = num / 10 --> 1232
// // temp = num --> temp = 1232
// //
// // (Remove all the repeating digit) -- > newNum = 13
// // newNum = 13 * 10 + digit --> newNum = 13 * 10 + 2 = 132
// // place = place * 10 --> place = 10
// // num = newNum --> num = 132
// //
// //
// // digit = ((num / place) % 10) --> digit = ((132 / 10) % 10) --> digit = ((13) % 10) --> digit = 3
// // num = num / 10 --> 13
