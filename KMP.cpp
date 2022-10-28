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

	//cout << "AFTER PREFIX LOGIC" << endl;
	/* KMP Psudocode from slides 
	int q = 0; //number of characters matched
	for (int i=0; i<n; i++) {
		do {
			cout << "loop #" << i << endl;
			if (pat[q+1]== txt[i]) {
				cout << "First If satisfied" << endl;
				q++;
			}
			if (q==m) {
				compare++;
				counter++;
				cout << "FOUND A MATCH" << endl;
				q = lps[q];
			}
		} while (q > 0 && pat[q+1] != txt[i]);*/



	int i = 0; // iterator for txt
	int j = 0; // iterator for pat
	while (i<n) {
		if (pat[j] == txt[i]) {
			if (j==m-1) {
				//return (1-m+1);
				cout << "FOUND A MATCH" << endl;
				counter++;
				compare++;
			}
			i++;
			j++;
		} else {
			j = lps[j]; 
		}

		if (j==0) {
			if (lps[i] != pat[0]) {
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
