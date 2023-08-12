// Encode system functions.

#include "encode.h"

void Find_in_Alphabet(char letter)
// To find the index of a letter in the alphabet
{
    // Init variables
    idx = 0;
    Letter_found = 0;

    // Loop to find a letter in alphabet
    for (int i = 0; i <= CSLEN; i++) {
        if (alphabet[i] == letter) {
            idx = i;
            Letter_found = 1;
            break;
        }
    }
}

void Find_in_codeset(char letter)
// To find the index of a letter in the codeset
{
    // Init variables
    idx = 0;
    Letter_found = 0;

    // Loop to find letter in codeset
    for (int i = 0; i <= CSLEN; i++) {
        if (codeset[i] == letter) {
            idx = i;
            Letter_found = 1;
            break;
        }
    }
}

void Shift_CodeSet(int shift)
// To shift the codeset to the left by the shift amount and wrap the rest
// to the end. Round robin fashion. Temp is dynamicly sized to the shift amount
// which changes for ever letter to be encoded.
{
    char *temp = (char *)malloc(shift);         // Holds the left set of chars

    for (int i = 0; i < shift; i++)             // Get the left set of chars
        temp[i] = codeset[i];

    for (int i = 0; i < CSLEN - shift; i++)     // Shift left the rest of the chars 
        codeset[i] = codeset[i + shift];

    for (int i = 0; i < shift; i++)             // Add the temp to the end of the chars
        codeset[(CSLEN - shift) + i] = temp[i];

    free(temp);                                 // Clear out temp
}

char* getSentenceFromUser() 
{
    char* sentence = (char*)malloc(MAX_SENTENCE_LENGTH * sizeof(char));

    if (sentence == NULL) 
    {
        printf("\n>> Memory allocation failed.\n");
        exit(1);
    }

    printf("\nPlease enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove newline character from the end of the sentence
    int len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') 
        sentence[len - 1] = '\0';

    return sentence;
}

void getInputKeys(int keys[], int* numKeys) {
    printf("\nPlease input keys in the format 1, 2, 3, ... (up to %d keys)\n", MAX_KEYS);
    printf("Each key value should be in the range from 1 to 13.\n");

    char input[100];
    printf("Enter keys: ");
    fgets(input, sizeof(input), stdin);

    *numKeys = 0;
    char* token = strtok(input, ",");
    while (token != NULL && *numKeys < MAX_KEYS) {
        int keyValue = atoi(token);
        if (keyValue >= 1 && keyValue <= 13) {
            keys[*numKeys] = atoi(token);
            (*numKeys)++;
        } else {
            printf("\nInvalid key value entered: %s\n", token);
            printf("Defaulting to a key value of 5");
            keys[*numKeys] = 5;
            (*numKeys)++;
        }
        token = strtok(NULL, ",");
    }
}
