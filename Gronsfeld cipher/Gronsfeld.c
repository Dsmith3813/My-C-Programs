// Program to apply the Gronsfeld cipher.
//
// The Gronsfeld cipher is a polyalphabetic substitution cipher, very similar
// to the Vigenère cipher. It was invented around 1744 by the Earl of
// Gronsfeld, José de Bronckhorst. A Gronsfeld cipher works like a series of Caesar ciphers.
// The secret key determines how many places each letter of the alphabet should be shifted.
// For example, if the secret key is 1234, the shift will be 1, 2, 3, 4, 1, 2, 3, 4, etc. The
// shift is done for each input letter of the message to be encrypted.
//
// The Gronsfeld cipher is vulnerable to letter frequency analysis, just like the Vigenère
// cipher. It has more limited key strength than Vigenère cipher, because the shift was
// limited between 0-9 for the original process. so unless the key is long it can be cracked
// by brute force methods. NOTE: This program key limit is from 1-13, 13 being half of 26. Also
// there isn't a limit on how many keys one can have. The algorithm works more like how a human
// would use the the cipher.
//
// Take a letter from the message.
// Look the letter up in the alphabet.
// Use the codeset letter that corresponds to the alphabet position.
// Simple hu?


// Encode system includes
#include "encode.h"
#include "encode.c"

// Simulated input data. My intent is that this is a function in an encryption
// program. This is the first step.
char data[] = "This is not the time, nor the place, for fun.";
int keys[] = {5, 7, 13, 10, 25, 9, 8, 3};  // Intentionally has an error.


// Do the stuff
int main(void) {
    
    // Get sizes
    int DataLen = strlen(data);
    int ks = sizeof(keys) / sizeof(keys[0]);

    printf("\nThe message is:  %s", data);

    // Ensure the key values are from 1 - 13. if the key value is not
    // within this range, change the value to a default of 5.
    for (int i = 0; i < ks; i++) {
        if (keys[i] < 1 || keys[i] > 13) 
            keys[i] = 5;
    }

    // Step up for the encryption
    char cipher[DataLen];                   // Holds the cipher text
    strcpy(cipher, data);                   // Just to init cipher variable

    // Change the input data to upper case
    for (int i = 0; i < DataLen; i++) 
        data[i] = toupper(data[i]);

    // Loop for encrypting Gronsfed Cipher. Note that we find the plain text alphabet,
    // and then encode it with the corresponding codeset character.
    for (int i = 0; i < DataLen; i++) {
        char letter = data[i];              // Grab a letter
        int shift = keys[i % ks];           // Get the shift value
        Shift_CodeSet(shift);               // Shift codeset
        Find_in_Alphabet(letter);           // Set the index

        // Encode. If letter was not found, then it might be a space or punctuation.
        // In either case, just move it to the cipher.
        if (Letter_found)
            cipher[i] = codeset[idx];
        else
            cipher[i] = letter;             
    }

    // Step up for the decryption
    int CipherLen = strlen(cipher);
    char decipher[CipherLen];
    strcpy(decipher, cipher);
    strcpy(codeset, alphabet);              // Reset codeset back to base

    // Loop for decrypting Gronsfed Cipher. Note that we find the ciphered letter in codeset,
    // and then encode it with the corresponding alphabet character.
    for (int i = 0; i < CipherLen; i++) {
        char letter = cipher[i];
        int shift = keys[i % ks];
        Shift_CodeSet(shift);
        Find_in_codeset(letter);

        if (Letter_found)
            decipher[i] = alphabet[idx];
        else
            decipher[i] = letter;
    }

    printf("\nThe cipher is:   %s", cipher);
    printf("\nThe decipher is: %s\n\n", decipher);

    return 0;
}
