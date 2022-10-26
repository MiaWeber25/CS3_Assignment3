//
//  Horspool.cpp
//  Assignment 3
//
//  Created by Brandon Kamplain on 10/25/22.
//

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

#define numOfChars 256

int ShiftTable(char []);
int HorspoolMatching(char [], char []);

int main()
{
    char txt[]= "ABAAABCD";
	char pat[] = "ABC";
	cout << HorspoolMatching(pat, txt) << endl;

    return 0;
}

int ShiftTable(char P[])
{
    int index = 0;
    int m = sizeof(P)/sizeof(P[0]);

    int table[m];

    while (index < m-1)
    {
        table[P[index]] = m - 1 - index;
        index++;
    }
    return *table;
}

int HorspoolMatching(char P[], char T[])
{
    int m = sizeof(P)/sizeof(P[0]);
    int n = sizeof(T)/sizeof(T[0]);
    int table[m];
    
    for (int i = 0; i < m; i++)
        table[i] = ShiftTable(&P[i]);
    
    int j = m-1;

    while (j <= n-1)
    {
        int k = 0;
        while ((k <= m-1) && P[m-1-k] == T[j-k])
        {
            k++;
        }
        if (k == m)
			return (j - m + 1);
		else
			j = j + table[T[j]];
    }
    return -1;
}