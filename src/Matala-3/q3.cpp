#include <iostream>

using namespace std;

#define SIZE 10

int FirstIndexOfNumberShownMultiple(int arr[SIZE] , int size , int value){
    int counter = 0;
    int index = 0;
    int temparr[SIZE] = {};
    int indextemp = 0;

    for (int i = 0; i < size; i++)
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



int countIterationOfCurledArray(int arr[SIZE], int size){
    int counter = 0;
    bool isChanged = false;
    int number = 0;
    int firstIndex = 0;
    int index = 0;
    int tempArray[SIZE] = {};
    int i = 0;
    for (int i = 0; i < size; i++) {
        tempArray[i] = arr[i];
    }

    while (i < size )
    {
        //cout << " " << i;
        firstIndex = FirstIndexOfNumberShownMultiple(tempArray,size,tempArray[i]);
        cout << " " << i << "-" << tempArray[i];
        
        if (firstIndex != -1 && isChanged == false)
        {
            isChanged = true;
            number = tempArray[i];
            index = firstIndex;
            if (index >= i)
            {
                i++;
            }
            else{
                i = index;
            }
            
        }
        else if(isChanged == true && tempArray[i] == number && index != i)
        {
            i=index;
            tempArray[i] = tempArray[i] +1;
            isChanged = false;

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
   // int arry[SIZE] = {1,3,4,5,6,5,3,17,6,10};
    //{1,9,4,8,7,5,3,17,6,10};

    cout << endl << countIterationOfCurledArray(arry , SIZE);
    
}
