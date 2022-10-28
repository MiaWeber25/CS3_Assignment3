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
    //int p = 0; // hash value for pattern
    //int t = 0; // hash value for txt
    int counter = 0;


    int c = 1;
    int p = 0;
    int t = 0;
    for (int i=0; i<M-1; i++) {
        c = (c * D) % q; //pow(k,m-1)%q

    }
    for (int i=0; i<M; i++) {
        p = (D*p + pat[i]) % q;
        t = (D*t + txt[i]) % q;
    }
    for (int i=0;i<=N-M;i++) {
        if (p==t) {
            for (int j=0;j<M;j++) {
                if (txt[i+j] != pat[j]) {
                    break;
                }
            }
            if (j==M) {
                //FOUND PATTERN!
                counter++;
            }
        }
        if (i<N-M) {
            t = (D*t-txt[i]*c + txt[i+M]) %q;
            if (t<0) {
                t = (t+q);
            }
        }
    }
    cout << "Number of Occurances: " << counter << endl;
}

