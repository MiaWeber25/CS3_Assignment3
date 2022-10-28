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
	cout << "AFTER PREFIX LOGIC" << endl;
	//cout << "LPS: " << *lps << endl;
	int q = 0; //number of characters matched
	/*for (int i=1; i<n; i++) {
		cout << "loop #" << i << endl;
		do {
			q = lps[q];
			if (pat[q]==txt[i]) {
				q++;
				cout << "inside if #1" << endl;
			} 
			cout << "GOT HERE #1" << endl;
			if (q == m) {
				compare++;
				counter++; //found the pattern at shift i-m
				q = lps[q];
				cout << "inside of if #2" << endl;
			}
		} while (q > 0 && pat[q] != txt[i]);
	}*/

	/*int i = 0; // txt index
	int j = 0; // pat index

	while ((n-i) >= (m-j)) { // length of txt > length of pat
		if (pat[j] == txt[i]) { 
			j++;
			i++;
			//compare++; //increment comparison counter
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
				i++;
		}
	}*/
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
