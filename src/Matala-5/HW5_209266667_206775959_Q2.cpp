// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
#include <string.h>
using namespace std;

void calcAndSort(char** Teams, char** Scores, int n, char** sortedTeams, int* sortedScores); // Function to calculate and sort teams based on their scores
int getPointFromSign(char sign); // // Function to convert a match result character (w, d, l) to points
int getTeamPoints(char* teamScores); // This function calculates the total points for a team based on their score string

const int MAX_STR_SIZE = 10; // Maximum length for team names and scores

int main(){
    int n, *groupScoresSorted;
    char **groupNames, **groupScores, **groupNamesSorted;

    cout << "Please enter teams number:" << endl;
    cin >> n;

    // Allocate dynamic memory for team names, scores, sorted team names and sorted scores
    groupNames = new char* [n];
    groupScores = new char* [n];
    groupNamesSorted = new char* [n];
    groupScoresSorted = new int[n];

    // Allocate dynamic memory for each team name, score and sorted team name
    for (int i = 0; i < n; i++) {
        groupNames[i] = new char[MAX_STR_SIZE];
        groupScores[i] = new char[MAX_STR_SIZE];
        groupNamesSorted[i] = new char[MAX_STR_SIZE];
    }

    cin.ignore(); // To avoid skipping the first line of input after cin >> n

    // Get team names and scores from the user
    for (int i = 0; i < n; i++) {
        cout << "Please enter team name: ";
        cin.getline(groupNames[i], MAX_STR_SIZE);
        cout << "Please enter team score: ";
        cin.getline(groupScores[i], MAX_STR_SIZE);
    }

    // Sort team names and scores based on their scores
    calcAndSort(groupNames, groupScores, n, groupNamesSorted, groupScoresSorted);

    // Output the sorted team names and scores
    for (int i = 0; i < n; i++) {
        cout << groupNamesSorted[i] << " " << groupScoresSorted[i] << endl;
    }

    // Clean up dynamic memory allocation to prevent memory leaks
    for (int i = 0; i < n; i++) {
        delete[] groupNames[i];
        delete[] groupScores[i];
        delete[] groupNamesSorted[i];
    }
    delete[] groupNames;
    delete[] groupScores;
    delete[] groupNamesSorted;
    delete[] groupScoresSorted;

    return 0;
}

// Function to calculate and sort teams based on their scores
void calcAndSort(char** Teams, char** Scores, int n, char** sortedTeams, int* sortedScores) {
    int tempNameLen, tempScore;
    char *tempName;

    // Copy team names and calculate their points from the score string
    for (int i = 0; i < n; i++) {
        strcpy(sortedTeams[i], Teams[i]);
        sortedScores[i] = getTeamPoints(Scores[i]);
    }

    // Sorting the teams based on their scores in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (sortedScores[j] < sortedScores[j + 1]) {
                // Swap the scores
                tempScore = sortedScores[j];
                sortedScores[j] = sortedScores[j + 1];
                sortedScores[j + 1] = tempScore;

                // Swap the team names
                tempNameLen = strlen(sortedTeams[j]);
                tempName = new char[tempNameLen]; // Temporarily store the team name for swapping
                strcpy(tempName, sortedTeams[j]);
                strcpy(sortedTeams[j], sortedTeams[j + 1]);
                strcpy(sortedTeams[j + 1], tempName);
                delete[] tempName; // Free the temporary memory used for swapping team names
            }
        }
    }
}

// Function to convert a match result character (w, d, l) to points
int getPointFromSign(char sign) {
    if (sign == 'w') {
        return 3; // Win: 3 points
    }
    else if (sign == 'd') {
        return 1; // Draw: 1 point
    }
    else {
        return 0; // Loss: 0 points
    }
}

// Function to calculate the total points for a team based on the score string
int getTeamPoints(char* teamScores) {
    int sumScores = 0;

    while (*teamScores != '\0') {
        sumScores += getPointFromSign(*teamScores); // Get the points for each match result character
        teamScores++;
    }

    return sumScores;
}
