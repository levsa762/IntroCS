// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>

#include <string.h>

#define N 100

using namespace std;

int splitSentenceReturnCountWords(char sentence[], char result[][N]) {
    int len = strlen(sentence);
    int row = 0, col = 0;

    for (int i = 0; i <= len; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            result[row][col] = '\0'; // Null-terminate the word
            row++;                   // Move to the next word
            col = 0;                 // Reset column index
        } else {
            result[row][col++] = sentence[i];
        }
    }

    return row; // Return the number of words
}

// Function to check if a character is a vowel
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function to rearrange a word based on the first vowel
void rearrangeOnVowel(const char input[], char output[]) {
    int len = strlen(input);
    int firstVowelIndex = -1;
    int index = 0;

    // Find the index of the first vowel
    for (int i = 0; i < len; i++) {
        if (firstVowelIndex == -1 && isVowel(input[i])) {
            firstVowelIndex = i;
        }
    }

    // Rearrange the word if a vowel was found
    if (firstVowelIndex != -1) {
        for (int i = firstVowelIndex; i < len; i++) {
            output[index++] = input[i];
        }
        for (int i = 0; i < firstVowelIndex; i++) {
            output[index++] = input[i];
        }
    } else {
        // Copy the word as is if no vowel is found
        for (int i = 0; i < len; i++) {
            output[index++] = input[i];
        }
    }

    output[index] = '\0'; // Null-terminate
}

// Function to convert a sentence to Pig Latin
void PigLatin(char sentence[]) {
    char tempArray[N][N];    // To hold the split words
    char output[N];          // To store the Pig Latin word
    const char waySuffix[] = "way";
    const char aySuffix[] = "ay";

    // Split the sentence into words
    int wordCount = splitSentenceReturnCountWords(sentence, tempArray);

    // Process each word
    for (int i = 0; i < wordCount; i++) {
        if (isVowel(tempArray[i][0])) {
            // If the word starts with a vowel, add "way"
            strcat(tempArray[i], waySuffix);
        } else {
            // Rearrange the word and add "ay"
            rearrangeOnVowel(tempArray[i], output);
            strcat(output, aySuffix);
            strcpy(tempArray[i], output); // Copy back to tempArray
        }
    }

    // Print the Pig Latin sentence
    for (int i = 0; i < wordCount; i++) {
        if (i > 0) cout << " ";
        cout << tempArray[i];
    }
    cout << endl;
}

void Blang(char c []){
    char tempSentence[N] = "\0";
    int length = strlen(c);
    char tempSumChars[4] = "lb";
    int index = 0;
    char singleChar[2] = "\0";

    for (int i = 0; i <= length+1; i++)
    {
        if(c[i] == 'a' || c[i]== 'i' || c[i]=='u' || c[i]=='o' || c[i]=='e'){
            tempSumChars[0] = c[i];
            tempSumChars[2] = c[i];
            strcat(tempSentence, tempSumChars);
            index+=3;
        }
        else{
            singleChar[0] = c[i]; 
            strcat(tempSentence, singleChar);
            index++;
        }
    }
    tempSentence[index] = '\0';
    cout << "the word is " <<  tempSentence;
}

int main(){

    char co[] = "hello trash";
    char coTemo[N][N] ;
    //Blang(co);
    /*
    int words_count = splitSentence(co,coTemo);
    cout << "Words in the sentence:" << endl;
    for (int i = 0; i < words_count; i++) {
        cout << coTemo[i] << endl;
    }
    */
   PigLatin(co);
}