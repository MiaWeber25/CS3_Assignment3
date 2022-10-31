/*
    Karp-Rabin Search Algorithm
    CSCI 250 Mia Weber & Brandon Kamplain
    10/30/2022
*/
#include <iostream>
#include <math.h>

using namespace std;

const int D = 256; // Number of chars in alphabet (ASCII = 256)

// Karp-Rabin matching algorithm
// Input: the pattern, the text, q (INT_MAX) to calculate hash values
void KRMatching(char pat[], char txt[], int q) { 
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j; // Iterators for for loops

    int counter = 0; // Count number of occurances in the text
    int compare = 0; // Count number of comparisons made
    int spurious = 0; // Count number of spurious hits (hashes match but txt and pat don't)


    int c = 1; 
    int p = 0; // Hash value for the pattern
    int t = 0; // Hash value for the text
    bool mismatch = false;

    for (i=0; i<M-1; i++) {
        c = (c * D) % q; // pow(k,m-1)%q
    }

    for (i=0; i<M; i++) { // Calculate the inital hashes for the text and the pattern
        p = (D*p + pat[i]) % q;
        t = (D*t + txt[i]) % q;
    }

    for (i=0;i<=N-M;i++) {
        compare++; // Increment comparison counter
        
        if (i>0) {
            t = (D*(t-txt[i-1]*c) + txt[(i-1)+M]) % q; // Calculate hash for new substring of txt
        }

        if (p==t) { // If the hashes match:
            mismatch = false;
            for (j=0;j<M && !mismatch;j++) {
                if (txt[i+j] != pat[j]) {
                    mismatch = true;
                    spurious++; // Found a spurious match
                }
            }
            if (!mismatch) {
                counter++; // Found a match -> increment the counter
            }
        }
    }
    cout << "Number of Occurances: " << counter << endl;
    cout << "Numer of Comparisons made: " << compare << endl;
    cout << "Spurious Matches: " << spurious << endl;
}

