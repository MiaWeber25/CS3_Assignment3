/*
    Karp-Rabin Search Algorithm
    CSCI 250 Mia Weber & Brandon Kamplain
    10/30/2022
*/
#include <iostream>
#include <math.h>

using namespace std;

const int D = 256; // number of chars in alphabet (ASCII = 256)


//void search(char pat[], char txt[], int q) //q is a prime number
void KRMatching(char pat[], char txt[], int q) { //k is last element of alpha -1 (255)
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;

    int counter = 0;
    int compare = 0;
    int spurious = 0;


    int c = 1;
    int p = 0; // hash value for the pattern
    int t = 0; // hash value for the text
    bool mismatch = false;

    for (i=0; i<M-1; i++) {
        c = (c * D) % q; //pow(k,m-1)%q
    }

    for (i=0; i<M; i++) {
        p = (D*p + pat[i]) % q;
        t = (D*t + txt[i]) % q;
    }
    for (i=0;i<=N-M;i++) {
        compare++;
        if (i>0) {
            t = (D*(t-txt[i-1]*c) + txt[(i-1)+M]) % q;
        }
        if (p==t) {
            //spurious++;
            mismatch = false;
            for (j=0;j<M && !mismatch;j++) {
                if (txt[i+j] != pat[j]) {
                    //break; //find match even if last chars don't - bug
                    //bool found
                    mismatch = true;
                    spurious++; 
                }
            }
           // if (j==M) {
            if (!mismatch) {
                //FOUND PATTERN!
                counter++;
            }
        }
       // if (i<N-M) {
        //    t = (D*(t-txt[i]*c) + txt[i+M]) % q;
       // }
    }
    cout << "Number of Occurances: " << counter << endl;
    cout << "Numer of Comparisons made: " << compare << endl;
    cout << "Spurious Matches: " << spurious << endl;
}

