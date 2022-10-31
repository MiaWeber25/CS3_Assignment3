//
//  Horspool.cpp
//  Assignment 3
//
//  Created by Brandon Kamplain on 10/25/22.
//

#include <iostream>
using namespace std;

#define numOfChars 256

void ShiftTable(char*, double, int[]);
void HorspoolMatching(char*, char*);


// The preprocessing function for Horspool's Shift Table
void ShiftTable(char *P, double size, int table[numOfChars])
{
    int index = 0;

    // Initialize all occurrences as -1
    for(index = 0; index < numOfChars; index++)
        table[index] = -1;
    
    // Fill the actual value of last occurrence of a character
    for(index = 0; index < size; index++)
        table[(int) P[index]] = index;
    
}

// Pattern searching function using ShiftTable()
void HorspoolMatching(char *P, char *T)
{
    int m = strlen(P);
    int n = strlen(T);
    //cout << "The size of the text is: " << n << endl;
    int table[numOfChars];
    int cnt = 0;
    int cmp = 0;

    // Fill the bad character array by calling the preprocessing function ShiftTable() for a given pattern
    ShiftTable(P, m, table);

    //shift of the pattern with respect to text
    int shift = 0;
    
    while(shift <= (n-m))
    {
        cmp++;

        int j = m-1;

        // Keep reducing index j of pattern while characters of pattern and text are matching at this shift
        while(j >= 0 && P[j] == T[shift+j])
            j--;
        
        // f the pattern is present at current shift, then index j will become -1 after the above loop
        if(j < 0)
        {
            cnt++;

            // Shift the pattern so that the next character in text aligns with the last occurrence of it in pattern. The condition shift + m < n is necessary for the case when pattern occurs at the end of text
            shift += (shift+m < n)? m-table[T[shift+m]] : 1;
        }
        else
            // Shift the pattern so that the bad character in text aligns with the last occurrence of it in pattern. The max function is used to make sure that we get a positive shift. We may get a negative shift if the last occurrence of bad character in pattern is on the right side of the current character.
            shift += max(1, j - table[T[shift+j]]);
    }

    cout << "Number of Occurances in the text: " << cnt << "\nNumber of comparisons made: " << cmp << endl;
}