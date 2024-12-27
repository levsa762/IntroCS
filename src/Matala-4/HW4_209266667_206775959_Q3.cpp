// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>

using namespace std;



#include <string.h> 


// funtion that checks if t is in s and count the times of the Occurrence, by taking range of t in s and increament by 1 the iteration and get to the next check till loop ends
int mystr(char s[], char t[]) {
    int count = 0; 
    bool isFound;
    int sLength = strlen(s);
    int tLength = strlen(t);

    
    for (int i = 0; i <= sLength - tLength; i++) {
        isFound = true; 


        for (int j = 0; j < tLength; j++) {
            if (s[i + j] != t[j]) {
                isFound = false; 
            }
        }
        if (isFound) {
            count++;
        }
    }
    return count; 
}

int main() {
    char s1[] = "abracabraadAbra";
    char t1[] = "h";

    cout << "Occurrences of \"" << t1 << "\" in \"" << s1 << "\": " << mystr(s1, t1) << endl;

    char s2[] = "abracadabraa";
    char t2[] = "a";

    cout << "Occurrences of \"" << t2 << "\" in \"" << s2 << "\": " << mystr(s2, t2) << endl;

    char s3[] = "bbbb";
    char t3[] = "bb";

    cout << "Occurrences of \"" << t3 << "\" in \"" << s3 << "\": " << mystr(s3, t3) << endl;

    return 0;
}
