/*
	KMP Searching Algorithm
	CSCI 250 Mia Weber
	10/30/2022
	Algorithm Psudocode referenced from D2L resource on KMP
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
	int m = strlen(pat);
	int n = strlen(txt);

	// Array to store longest prefix suffix (LPS) table values
	double lps[m];

	prefix(pat, m, lps); // Call prefix function to compute LPS array

	int i = 0; // Iterator for txt
	int j = 0; // Iterator for pat

	while (i<n) {
		compare++; // Made a comparison -> increment comparison counter
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}
		if (j==m) {
			counter++; // Found a match -> increment counter
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
	cout << "Number of occurances in the text is: " << counter << endl;
	cout << "Number of comparisons: " << compare << endl;
}

// Populates lps array for the pattern
void prefix(char* pat, int m, double* lps) {
	int length = 0; // Length of previous longest prefix suffix

	lps[0] = 0; // lps[0] is always 0
	// Populates lps for i=1 to m-1
	int i = 1;
	
	for (i=1; i<m; i++) {
		do {
			length=lps[length];
			if (pat[length+1] == pat[i+1]) {
				length++; 
			}
			lps[i+1] = length;
		} while (length > 0 && pat[length+1]!=pat[i+1]);
	}
}
