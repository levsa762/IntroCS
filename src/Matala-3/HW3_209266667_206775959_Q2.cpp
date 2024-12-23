// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>

using namespace std;

#define N 19



/* this function gets an array and its size , it checks for the longest positive numbers in the array by looping through and counting. it compares 
with max counter and then calculate the max, it stores the starting index of the longest section, and at the end it prints from the starting index , max counter num times, so with that
it will print the longest positive section . if there is not positive numbers in the array it prints messeage of none positive numbers in the array.
*/
void longestSection(int A[], int size){
    int counter = 0;
    int max = 0 ;
    int maxIndex = 0;
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (A[i] > 0)
        {
            counter ++;
        }

        if (A[i] <= 0 || i == (size -1))
        {
            if (counter > max)
            {
                max = counter;
                maxIndex = index;
            }

            index = i + 1;
            counter =0;
        }
    }

    if (max > 0)
    {
        cout << "The longest section starts at index " << maxIndex << " its length is: " << max << endl;
        cout << "The section is: ";
        for (int i = maxIndex; i < (maxIndex+max); i++)
        {
            cout << " " << A[i];
        }
    }
    else {
        cout << "This is array without positive" << endl;
    }
}

int main(){
    int arr[N] = {};
    int num;
    cout << "Please enter a series ";
    for(int i = 0 ;i<N; i++ ){
        cout << " ";
        cin >> num;
        arr[i] = num;
    }
    cout << endl;
    longestSection(arr, N);
    // for run , just copy and paste this
    // 1 -4 5 6 7 0 -8 0 1 0 9 -100 -99 -1 5 67 2 1 -15
    // -1 -4 -5 -6 -7 -1 -8 -1 -1 -1 -9 -100 -99 -1 -5 -67 -2 -1 -15
}
