//
//  Horspool.cpp
//  Assignment 3
//
//  Created by Brandon Kamplain on 10/25/22.
//

#include <iostream>
using namespace std;

#define numOfChars 256

void ShiftTable(char*, int, int[]);
void HorspoolMatching(char*, char*);

/*
int main()
{
    char txt[] = "ABAAABCD";
	char pat[] = "ABC";
	HorspoolMatching(pat, txt);

    return 0;
}
*/

void ShiftTable(char *P, int size, int table[numOfChars])
{
    int index = 0;

    for(index = 0; index < numOfChars; index++)
        table[index] = -1;
    
    for(index = 0; index < size; index++)
        table[(int) P[index]] = index;
    
}

void HorspoolMatching(char *P, char *T)
{
    int m = strlen(P);
    int n = strlen(T);
    int table[numOfChars];

    ShiftTable(P, m, table);

    int shift = 0;
    
    while(shift <= (n-m))
    {
        int j = m-1;

        while(j >= 0 && P[j] == T[shift+j])
            j--;
        
        if(j < 0)
        {
            cout << "pattern occurs at shift " << shift << endl;

            shift += (shift+m < n)? m-table[T[shift+m]] : 1;
        }
        else
            shift += max(1, j - table[T[shift+j]]);
    }
}