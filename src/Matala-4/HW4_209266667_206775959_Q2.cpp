// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

int bSearch (int arr[], int arrSize, int num);

int main(){
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, arrSize = 10, num;

    cout << "Please enter a num: " << endl;
    cin >> num;

    cout << "The index of number " << num << " is: " << bSearch(arr, arrSize, num) << endl;
}

int bSearch (int arr[], int arrSize, int num) {
    int low = 0, high = arrSize - 1, result = -1, mid;

    while (result == -1 && (low <= high)) {
        mid = (low + high) / 2;

        if (arr[mid] == num) {
            result = mid;
        }
        else if (arr[mid] > num) {
            low = mid + 1;
        }
        else if (arr[mid] < num) {
            high = mid - 1;
        }
    }

    return result;
}
