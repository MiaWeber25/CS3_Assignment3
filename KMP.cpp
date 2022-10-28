/*
	KMP Searching Algorithm
	CSCI 250 Mia Weber & Brandon Kamplain
	10/30/2022
*/
    #include <iostream>
    #include <fstream>
	
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

	int i = 0; // txt index
	int j = 0; // pat index

	while ((n-i) >= (m-j)) { // length of txt > length of pat
		if (pat[j] == txt[i]) { 
			j++;
			i++;
			compare++; //increment comparison counter
		}

		if (j==m) { // pattern found at [i-j]
			counter++; //increment occurance counter
			j = lps[j - 1];
			compare++; //increment comparison counter
		}

		else if (i<n && pat[j] != txt[i]) { //found a mismatch
			//don't need to match [0-lps[j-1]] -> they will match
			if (j != 0) {
				j = lps[j - 1];
			} else
				i = i + 1;
		}
	}
	cout << "Number of Occurances in the text: " << counter << endl;
	cout << "Number of comparisons made: " << compare << endl;
}

// populates lps array for the pattern
void prefix(char* pat, int m, double* lps) {
	int length = 0; // length of previous longest prefix suffix

	lps[0] = 0; // lps[0] is always 0

	//populates lps for i=1 to m-1
	int i = 1;
	
	while (i<m) {
		if (pat[i] == pat[length]) {
			length++;
			lps[i] = length;
			i++;
		}
		else // (pat[i] != pat[length])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			//if (len != 0) {
			if(length != 0) {
				//len = lps[len - 1];
				length = lps[length-1];
			}
			else {// (len == 0)
				lps[i] = 0;
				i++;
			}
		}
	}
}
