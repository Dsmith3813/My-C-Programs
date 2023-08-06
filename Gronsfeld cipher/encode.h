// Header file for encode system. Has everything needed by the encode
// system.

#ifndef ENCODE
#define ENCODE
 
// The includes
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables
#define CSLEN 26            // Length of alphabet.

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Base
char codeset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // Codeset to be shifted for encoding

int idx = 0;                // index into either alphabet or codeset
int Letter_found = 0;       // Boolean; 1 true, 0 false

// The functions
void Find_in_Alphabet(char letter);
void Find_in_codeset(char letter);
void Shift_CodeSet(int shift);


#endif