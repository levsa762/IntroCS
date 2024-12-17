#include <iostream>

using namespace std;

#define SIZE 10

/* function that finds if value is in array more then once(looping until index equals index of the value) and returns the first index of the value if it 
true , if not it will return -1
*/

int FirstIndexOfNumberShownMultiple(int arr[] , int size , int value , int indexl){
    int counter = 0;
    int index = 0;
    int temparr[SIZE] = {};
    int indextemp = 0;

    for (int i = 0; i < indexl+1; i++)
    {
        if (arr[i] == value)
        {
            counter++;
            temparr[indextemp] = i;
            indextemp++;
        } 
    }
    if (counter > 1)
    {
        return temparr[0];
    }
    return -1;
}


/* function that looping through an array and make it curly(each value of cell is differet from each other)
we are looping through the tempArray and every time "add" value to him, it checks with side fucntion if value in the temp array has at least duplication , if yes it jumps to the index
up the value by one and keep doing it untill the temp array is curly, the fucntion returns a counter that counts the number of cells he "jumped"
*/
int countIterationOfCurledArray(int arr[], int size){
    int counter = 0;
    int number = 0;
    int firstIndex = 0;
    int index = 0;
    int tempArray[SIZE] = {0};
    int i = 0;

    while (i < size ){

        if(tempArray[i]==0){
            tempArray[i] = arr[i];
        }

        cout << " " << i ;
        firstIndex = FirstIndexOfNumberShownMultiple(tempArray,size,tempArray[i], i);
        
        if (firstIndex != -1){
            i=firstIndex;
            tempArray[i] = tempArray[i] +1;
        }

        else{
               i++;
            }
            
        counter++;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << " " << tempArray[i];
    }

    cout << endl;
    
    return counter;

}








int main(){

    int arry[SIZE] = {1,11,4,5,2,9,4,12,17,6};
   //int arry[SIZE] = {1,3,4,5,6,5,3,17,6,10};
    //{1,9,4,8,7,5,3,17,6,10};

    cout << endl << countIterationOfCurledArray(arry , SIZE);
    
}
