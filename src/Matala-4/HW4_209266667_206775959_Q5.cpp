// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

void BLanguageGame();
void PigLatinGame();
void subString(char source[], int start, int end, char dest[]);

int main(){
    int choose;

    cout << "Please choose:" << endl;
    cout << "1: Pig Latin" << endl;
    cout << "2: B Language" << endl;
    cout << "0: Finish" << endl;
    cin >> choose;

    while (choose != 0) {
        cin.ignore();

        if (choose == 1) {
            PigLatinGame();
        }
        else if (choose == 2) {
            BLanguageGame();
        }
        else {
            cout << "Please choose a valid option." << endl;
        }

        cout << "Please choose:" << endl;
        cout << "1: Pig Latin" << endl;
        cout << "2: B Language" << endl;
        cout << "0: Finish" << endl;
        cin >> choose;
    }
}

void BLanguageGame() {
    int textIndex = 0, newTextIndex = 0, tempStrIndex, firstWordIndex = 0, lastWordIndex;
    char text[100], newText[200], tempStr[100];
    cout << "Please enter a sentence (max 100 char): " << endl;
    cin.getline(text, 100);

    while (text[textIndex] != '\0') {
        if ((text[textIndex] == ' ') || (text[textIndex] == '.')) {
            lastWordIndex = textIndex - 1; // Minus 1 for removing get the last index of word without space or dot.
            subString(text, firstWordIndex, lastWordIndex, tempStr);
            tempStrIndex = 0;

            while (tempStr[tempStrIndex] != '\0') {
                newText[newTextIndex] = tempStr[tempStrIndex];
                newTextIndex++;
                if ((tempStr[tempStrIndex] == 'a') || (tempStr[tempStrIndex] == 'e') || (tempStr[tempStrIndex] == 'i') || (tempStr[tempStrIndex] == 'o') || (tempStr[tempStrIndex] == 'u')) {
                    newText[newTextIndex] = 'b';
                    newTextIndex++;
                    newText[newTextIndex] = tempStr[tempStrIndex];
                    newTextIndex++;
                }
                tempStrIndex++;
            }
            newText[newTextIndex] = text[textIndex];
            newTextIndex++;

            firstWordIndex = lastWordIndex + 2; // Plus 1 for a space, plus another 1 for beginning of next first word.
        }

        textIndex++;
    }
    newText[newTextIndex] = '\0';

    cout << "Output: " << newText << endl;
}

void PigLatinGame() {
    int textIndex = 0, newTextIndex = 0, tempStrIndex, tempStrAfterVowelIndex, tempStrUntilVowelIndex, firstWordIndex = 0, lastWordIndex;
    char text[100], newText[200], tempStr[100], tempStrUntilVowel[100], tempStrAfterVowel[100];
    cout << "Please enter a sentence (max 100 char): " << endl;
    cin.getline(text, 100);

    while (text[textIndex] != '\0') {
        if ((text[textIndex] == ' ') || (text[textIndex] == '.')) {
            lastWordIndex = textIndex - 1; // Minus 1 for removing get the last index of word without space or dot.
            subString(text, firstWordIndex, lastWordIndex, tempStr);
            tempStrIndex = 0;

            if ((tempStr[tempStrIndex] == 'a') || (tempStr[tempStrIndex] == 'e') || (tempStr[tempStrIndex] == 'i') || (tempStr[tempStrIndex] == 'o') || (tempStr[tempStrIndex] == 'u')) {
                while (tempStr[tempStrIndex] != '\0') {
                    tempStrIndex++;
                }
                tempStr[tempStrIndex++] = 'w';
                tempStr[tempStrIndex++] = 'a';
                tempStr[tempStrIndex++] = 'y';
                tempStr[tempStrIndex] = '\0';
            }
            else {
                while ((tempStr[tempStrIndex] != 'a') && (tempStr[tempStrIndex] != 'e') && (tempStr[tempStrIndex] != 'i') && (tempStr[tempStrIndex] != 'o') && (tempStr[tempStrIndex] != 'u')) {
                    tempStrIndex++;
                }
                // Create tempStrUntilVowel - array of char. This array hold the char before vowel.
                subString(tempStr, 0, tempStrIndex - 1, tempStrUntilVowel);

                // Create tempStrAfterVowel - array of char. This array hold the char after vowel.
                tempStrAfterVowelIndex = 0;
                while (tempStr[tempStrIndex] != '\0') {
                    tempStrAfterVowel[tempStrAfterVowelIndex] = tempStr[tempStrIndex];
                    tempStrAfterVowelIndex++;
                    tempStrIndex++;
                }
                tempStrAfterVowel[tempStrAfterVowelIndex] = '\0';

                // Copy tempStrUntilVowel into tempStr from index 0.
                tempStrIndex = 0;
                tempStrAfterVowelIndex=0;
                while (tempStrAfterVowel[tempStrAfterVowelIndex] != '\0') {
                    tempStr[tempStrIndex] = tempStrAfterVowel[tempStrAfterVowelIndex];
                    tempStrIndex++;
                    tempStrAfterVowelIndex++;
                }

                // Append tempStrUntilVowel into tempStr.
                tempStrUntilVowelIndex = 0;
                while (tempStrUntilVowel[tempStrUntilVowelIndex] != '\0') {
                    tempStr[tempStrIndex] = tempStrUntilVowel[tempStrUntilVowelIndex];
                    tempStrIndex++;
                    tempStrUntilVowelIndex++;
                }
                tempStr[tempStrIndex] = 'a';
                tempStrIndex++;
                tempStr[tempStrIndex] = 'y';
                tempStrIndex++;
                tempStr[tempStrIndex] = '\0';
            }

            // Append the new word into newText array.
            tempStrIndex = 0;
            while (tempStr[tempStrIndex] != '\0') {
                newText[newTextIndex] = tempStr[tempStrIndex];
                newTextIndex++;
                tempStrIndex++;
            }
            newText[newTextIndex] = text[textIndex];
            newTextIndex++;

            firstWordIndex = lastWordIndex + 2; // Plus 1 for a space, plus another 1 for beginning of next first word.
        }

        textIndex++;
    }
    newText[newTextIndex] = '\0';

    cout << "Output: " << newText << endl;
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
