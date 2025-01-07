// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>

using namespace std;
#include <cstring>

#define MAXSIZE 10

// Converts a score string to a numerical value
int scoreToNumber(char arr []){
    int sum = 0;
    while (*arr)
    {
        if (*arr == 'w')
        {
            sum+=3;
        }
        else if (*arr == 'd')
        {
            sum+=1;
        }
        arr++; 
    }
    return sum;
}

// Calculates scores and sorts teams based on their scores
void calcAndSort(char** Teams, char** Scores, int n, char** sortedTeams, int* sortedScores){
    // Calculate scores
    for (int i = 0; i < n; i++)
    {
        sortedScores[i] = scoreToNumber(Scores[i]);
    }
    // Copy team names
    for (int i = 0; i < n; i++)
    {
        strcpy(sortedTeams[i], Teams[i]);
    }
    char tempc[MAXSIZE] = {};
    int tempnum = 0;

    // Sort teams and scores in descending order
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n-j-1; i++)
        {
            if (sortedScores[i] < sortedScores[i+1])
            {
                tempnum = sortedScores[i+1];
                sortedScores[i+1] = sortedScores[i];
                sortedScores[i] = tempnum;

                strcpy(tempc, sortedTeams[i+1]);
                strcpy(sortedTeams[i+1], sortedTeams[i]);
                strcpy(sortedTeams[i], tempc);
            }   
        }   
    }
}

int main(){
    cout << "Enter number of teams: " << endl;
    int N;
    cin >> N;
    cin.ignore(); // Ignore the newline character left in the buffer

    char** teamsArray = new char*[N];
    char** scoresArray = new char*[N];
    for (int i = 0; i < N; i++) {
        teamsArray[i] = new char[MAXSIZE];
        scoresArray[i] = new char[MAXSIZE];
    }

    for (int i = 0; i < N; i++) {
        cout << "Please enter team name: " << endl;
        cin >> teamsArray[i];
        cout << "Please enter team score: " << endl;
        cin >> scoresArray[i];
    }

    int sortedScores[N];
    char** sortedTeams = new char*[N];
    for (int i = 0; i < N; ++i) {
        sortedTeams[i] = new char[MAXSIZE];
    }

    // Calculate and sort teams based on scores
    calcAndSort(teamsArray, scoresArray, N, sortedTeams, sortedScores);

    // Print sorted teams and scores
    for (int i = 0; i < N; i++) {
        cout << sortedTeams[i] << " " << sortedScores[i] << endl;
    }

    // Free allocated memory
    for (int i = 0; i < N; ++i) {
        delete[] teamsArray[i];
        delete[] scoresArray[i];
        delete[] sortedTeams[i];
    }
    delete[] teamsArray;
    delete[] scoresArray;
    delete[] sortedTeams;

    return 0;
}



