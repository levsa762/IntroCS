// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <strings.h>
#include <iostream>
using namespace std;

int myStr(char s[], char t[]);
void subString(char source[], int start, int end, char dest[]);

int main(){
    char s[] = "abracadabra", t[] = "ab";

    cout << "The amount of " << t << " in " << s << " is: " << myStr(s,t) << endl;

    return 0;
}

int myStr(char s[], char t[]) {
    int count = 0, strLenS = strlen(s), strLenT = strlen(t);
    char strTemp[strLenT + 1];

    for (int i = 0; i <= strLenS - strLenT; i++) {
        subString(s, i, i + strLenT - 1, strTemp);

        if (strcmp(t, strTemp) == 0) {
            count++;
        }
    }

    return count;
}

void subString(char source[], int start, int end, char dest[]) {
    int j = 0;

    if (start >= 0 && end >= start && start < strlen(source)) {
        for (int i = start; i <= end; i++) {
            dest[j] = source[i];
            j++;
        }
        dest[j] = '\0';
    }
}
