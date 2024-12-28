// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 3
int mapSequences(char strMat[][50] ,int rows){

    int maxc= 0;
    char tempArray[50]="t";
    int c1 = 0;
    int c0 = 0;
    int indexTemp = 0;

    for (int i = 0; i < rows; i++)
    {
        //tempArray[0] = '\0' ;
        indexTemp = 0;
        for (int j = 0; strMat[i][j] != '\0' ; j++)
        {        
        if (strMat[i][0] != '1') {
            tempArray[0] = '0';
            indexTemp++;
        }
        if (strMat[i][j] == '1')
        {
            c1++;
            if (strMat[i][j+1] == '0')
            {
                tempArray[indexTemp]=c1;
                c1=0;
                indexTemp++;
            } 
            
        }

        if (strMat[i][j] == '0')
        {
            c0++;
            if (strMat[i][j+1] == '1')
            {
                tempArray[indexTemp]=c1;
                c0=0;
                indexTemp++;
            } 
            
        }
    }
    cout << "the number is " << indexTemp;
    tempArray[indexTemp+1] = '\0';
    cout << tempArray;
    cout << endl;
    if (strlen(tempArray) > maxc)
    {
        maxc = strlen(tempArray);
    }
   } 
    return maxc;
}

int main(){

    //char mo[] = {'p', 'p', '\0', 'l', 'o', '\0'};
    //cout << strlen(mo);
    char co [SIZE][50] = {"0000000" ,"10101" ,"11000001"};

    mapSequences(co, SIZE);
}