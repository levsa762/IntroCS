// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
#include <string.h>
using namespace std;

void calcAndSort(char** Teams, char** Scores, int n, char** sortedTeams, int* sortedScores);
int getPointFromSign(char sign);
int getTeamPoints(char* teamScores);

const int MAX_STR_SIZE = 10;

int main(){
    int n;

    cout << "Please enter team numbers:" << endl;
    cin >> n;

    cin.ignore();
    char** groupNames = new char* [n];
    char** groupScores = new char* [n];
    for (int i = 0; i < n; i++) {
        groupNames[i] = new char[MAX_STR_SIZE];
        groupScores[i] = new char[MAX_STR_SIZE];
    }

    for (int i = 0; i < n; i++) {
        cout << "Please enter team name:" << endl;
        cin.getline(groupNames[i], MAX_STR_SIZE);
        cout << "Please enter team score:" << endl;
        cin.getline(groupScores[i], MAX_STR_SIZE);
    }

    int* groupScoresSorted = new int[n];
    char** groupNamesSorted = new char* [n];
    for (int i = 0; i < n; i++) {
        groupNamesSorted[i] = new char[MAX_STR_SIZE];
    }

    calcAndSort(groupNames, groupScores, n, groupNamesSorted, groupScoresSorted);

    for (int i = 0; i < n; i++) {
        cout << groupNamesSorted[i] << " " << groupScoresSorted[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] groupNames[i];
        delete[] groupScores[i];
    }
    delete[] groupNames;
    delete[] groupScores;

    return 0;
}

void calcAndSort(char** Teams, char** Scores, int n, char** sortedTeams, int* sortedScores) {
    for (int i = 0; i < n; i++) {
        strcpy(sortedTeams[i], Scores[i]);
        sortedScores[i] = getTeamPoints(Scores[i]);
    }

}

int getPointFromSign(char sign) {
    if (sign == 'w') {
        return 3;
    }
    else if (sign == 'd') {
        return 1;
    }
    else {
        return 0;
    }
}

int getTeamPoints(char* teamScores) {
    int sumScores = 0;

    while (*teamScores != '\0') {
        sumScores += getPointFromSign(*teamScores);
        teamScores++;
    }

    return sumScores;
}
