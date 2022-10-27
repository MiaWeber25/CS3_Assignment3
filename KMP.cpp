// C++ program for implementation of KMP pattern searching
// algorithm
//#include <bits/stdc++.h>
    #include <iostream>
    #include <fstream>
	
    using namespace std;

void computeLPSArray(char* pat, int M, double* lps);


// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	int counter = 0;
	int compare = 0; //comparison counter not working. One time 0 comparisons -> should never be 0 comparisons...
	int M = strlen(pat);
	int N = strlen(txt);
	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	double lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);
	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
			//increment comparisons counter??
			compare++;
		}

		if (j == M) {
			//printf("Found pattern at index %d ", i - j);
            //cout << "Found pattern at index: " << i-j << endl;
			counter++;
			j = lps[j - 1];
			//increment comparisons counter??
			compare++;
		}

		// mismatch after j matches --> NO MORE COMPARISONS ARE MADE???? 
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0) {
				j = lps[j - 1];
			} else
				i = i + 1;
		}
		//comparison counter finished here??
	}
	cout << "Number of Occurances in the text: " << counter << endl;
	cout << "Number of comparisons made: " << compare << endl;
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, double* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Driver program to test above function
/*int main()
{
	//get the file name from the user
	string fileName;
	cout << "Enter file name: " << endl;
	cin >> fileName;

	fstream myFile;
	myFile.open(fileName);
	//myFile.open("text.txt"); //open the file
	//------------------------------------------
	myFile.seekg(0,ios::end); //Go to the final char of the text file
	unsigned int fileSize = myFile.tellg(); //determine length of 
	cout << "\n File Size: " << fileSize << endl;
	char txt[fileSize]; //array length needed

	//------------------------------------------
	myFile.seekg(0,ios::beg);
	myFile.read(txt, fileSize); //SHERINE CODE
	//auto stop = high_resolution_clock::binary();

	myFile.close(); //close the file

	//char txt[] = "I Went To The Store Yesterday.";
	cout << "\n TXT: " << txt << endl;
	char pat[] = "To The";
	cout << "\n PAT: " << pat << endl;
	KMPSearch(pat, txt);
	cout << "\n AFTER SEARCH" << endl;
	return 0;
}*/

