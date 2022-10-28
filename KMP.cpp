/*
	KMP Searching Algorithm
	CSCI 250 Mia Weber & Brandon Kamplain
	10/30/2022
*/
    #include <iostream>
    #include <fstream>
	#include <cstring>
	
    using namespace std;

// Function prototype for prefix function
void prefix(char* pat, int m, double* lps);

// Find the number of occurances in the pattern
void KMP(char* pat, char* txt) {
	int counter = 0; // # of occurances
	int compare = 0; // # of comparisons
	// comparison counter not working. One time 0 comparisons -> should never be 0 comparisons...
	int m = strlen(pat);
	int n = strlen(txt);

	// array to store longest prefix suffix (LPS) table values
	double lps[m];

	prefix(pat, m, lps); // call prefix function to compute LPS array

	int i = 0; // iterator for txt
	int j = 0; // iterator for pat
	while (i<n) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
			compare++;
		}
		if (j==m) {
			counter++;
			compare++;
			j = lps[j-1];
		}
		else if (i<n && pat[j] != txt[i]) {
			if (j != 0) {
				j = lps[j-1];
			} else {
				i++;
			}
		}
	}
	cout << "Number of Occurances in the text: " << counter << endl;
	cout << "Number of comparisons made: " << compare << endl;
}

// populates lps array for the pattern
void prefix(char* pat, int m, double* lps) {
	int length = 0; // length of previous longest prefix suffix

	lps[0] = 0; // lps[0] is always 0
//new comment
	//populates lps for i=1 to m-1
	int i = 1;
	
	//cout << "above logic" << endl;
	for (i=1; i<m; i++) {
	//cout << "in for loop. i = " << i << endl;
		do {
			length=lps[length];
			if (pat[length+1] == pat[i+1]) {
				length++; 
			}
			lps[i+1] = length;
		} while (length > 0 && pat[length+1]!=pat[i+1]);
	}
}
