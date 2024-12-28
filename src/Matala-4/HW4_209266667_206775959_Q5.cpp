// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959
#include <iostream>

#include <string.h>

#define N 100

using namespace std;


// Splits sentance to an array of words and returns how much words in this array - not including the dot
int splitSentenceReturnCountWords(char sentence[], char result[][N]) {
    int len = strlen(sentence);
    int row = 0, col = 0;

    // Check if the last character is a dot, and replace it with \0
    if (sentence[len - 1] == '.') {
        sentence[len - 1] = '\0';
        len--; // Decrease the length by 1 to not include the dot in processing
    }
    // do the split, after every word put \0 to split.
    for (int i = 0; i <= len; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            result[row][col] = '\0'; 
            row++;                   
            col = 0;                 
        } else {
            result[row][col] = sentence[i];
            col++;
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
            output[index] = input[i];
            index++;
        }
        for (int i = 0; i < firstVowelIndex; i++) {
            output[index] = input[i];
            index++;
        }
    } else {
        // Copy the word as is if no vowel is found
        for (int i = 0; i < len; i++) {
            output[index] = input[i];
            index++;
        }
    }

    output[index] = '\0'; // Null-terminate
}

// Function to convert a sentence to Pig Latin
void PigLatin(char sentence[]) {
    char tempArray[N][N];    
    char output[N];          
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
    cout << "output: ";
    for (int i = 0; i < wordCount; i++) {
        if (i > 0) cout << " ";
        cout << tempArray[i];
    }
    //Adding the dot which removed from the last word 
    cout << '.';
    cout << endl;
}


// Adding b and a vowel after discover vowel in the word - ex : ub - ubub
void Blang(char c []){
    char tempSentence[N] = "\0";
    int lengthOfSentance = strlen(c);
    char tempSumChars[4] = "lb"; //template to swap the before b place and add value to the place after  , ex- "ubu\0"
    int index = 0; // Index for putting \0 when needed to create a word(split to a word)
    char singleChar[2] = "\0"; // temp array for holding the current iteration value of array
    
    //looping through all chars in the string
    for (int i = 0; i <= lengthOfSentance; i++)
    {   
        if(isVowel(c[i])){
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
    cout << "output: " <<  tempSentence << endl;
}


// Initialize new language game with call to this func
void GameLanguage(){
    int choice  = 90;
    char arr[N];
    while (choice != 0)
    {
        cout << "Please choose: " << endl << "1: Pig-Latin" << endl << "2: B-Language" << endl << "0: Finish" << endl;
        cin >> choice ;
        cin.ignore();
        cout << endl;
        //Menu of the game
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Please enter a sentance" << endl;
            cin.getline(arr,N);
            PigLatin(arr);
            break;
        case 2:
            cout << "Please enter a sentance" << endl;
            cin.getline(arr,N);
            Blang(arr);
            break;
        
        default:
            cout << "you did not choose number from the list , to get out press 0";
            break;
        }
    }
}

int main(){
   GameLanguage();
}