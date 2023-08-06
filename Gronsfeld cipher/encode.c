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
