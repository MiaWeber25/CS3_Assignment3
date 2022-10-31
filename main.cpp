/*
	Assignment 3 Driver Code
	CSCI 250 Mia Weber & Brandon Kamplain
	10/30/2022
    Useful resource: https://stackoverflow.com/questions/30696639/increase-the-maximum-size-of-char-array 
*/
#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>

#include "KMP.cpp"
#include "Horspool.cpp"
#include "Karp-Rabin.cpp"

using namespace std;
using namespace chrono;

// Function prototypes:
void search();
void quit();
void menu(int);

int main() {
    // S for search Q for quit
    char input = 'S';
    while (input == 'S') {
        cout << "Welcome! Please enter 'S' for search and 'Q' for quit: " << endl;
        cin >> input;
        menu(input);
    }  
}

void menu(int input) { // Print menu for user
    switch(input) {
        case 'S': { // Search was selected
            search();
            break;
        }
        case 'Q': { // Quit was selected
            quit();
            break;
        }
    }
}

void search() { // Logic to call searching algorithms
    // Get file name from user:
    string fileName;
    cout << "Please specify input text file name: " << endl;
    cin.ignore();
    getline(cin, fileName);

    
    // Open the file:
    fstream myFile;
    myFile.open(fileName);

    // Determine the size of the file:
    myFile.seekg(0, ios::end); //final char of .txt file
    unsigned int fileSize = myFile.tellg();

    // TESTING: ***DELETE LATER***
    cout << "\n The size of the file is: " << fileSize << endl;

    // Create the char array to store the text from the file:
    char * txt;
    txt = (char*) malloc (100*sizeof(char));
    if (txt==NULL) exit (1);

    // Get the pattern from the user:
    int MAX_SIZE = 1000;
    char pat[MAX_SIZE]; 
    cout << "enter pattern: " << endl;
    cin.getline(pat, MAX_SIZE); 
    cout << "pat[] = " << pat << endl;
    

    // Start the clock:
    auto start = high_resolution_clock::now();
    myFile.seekg(0,ios::beg);
	myFile.read(txt, fileSize); // Read the file
    //Stop the clock:
    auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<milliseconds>(stop-start);
    auto duration_ns = duration_cast<nanoseconds>(stop - start);
    auto duration_mis = duration_cast<milliseconds>(stop - start);
    cout << endl << "Total time elapsed: \n";
    cout << "Text read! Time to read: " << duration_ns.count() << " nanoseconds\n" << endl;
    myFile.close(); // Close the file

    // Call search functions:

    // KMP search algorithm function call:
    cout << "KMP:\n";
    start = high_resolution_clock::now();
    KMP(pat, txt);
    stop = high_resolution_clock::now();
    duration_ns = duration_cast<nanoseconds>(stop - start);
    duration_mis = duration_cast<milliseconds>(stop - start);
    cout << "Time: " << duration_mis.count() << " milliseconds\nTime: " << duration_ns.count() << " nanoseconds\n";

    //Horspool search algorithm function call:
    cout << "\nHorspool:\n";
    start = high_resolution_clock::now();
    HorspoolMatching(pat, txt); 
    stop = high_resolution_clock::now();
    duration_ns = duration_cast<nanoseconds>(stop - start);
    duration_mis = duration_cast<milliseconds>(stop - start);
    cout << "Time: " << duration_mis.count() << " milliseconds\nTime: " << duration_ns.count() << " nanoseconds\n";
    
    //Karp Rabin search algorithm function call:
    cout << "\nKarp-Rabin:\n";
    start = high_resolution_clock::now();
    int q = INT_MAX; // Used for calculation of hashes
    KRMatching(pat, txt, q);
    stop = high_resolution_clock::now();
    duration_ns = duration_cast<nanoseconds>(stop - start);
    duration_mis = duration_cast<milliseconds>(stop - start);
    cout << "Time: " << duration_mis.count() << " milliseconds\nTime: " << duration_ns.count() << " nanoseconds\n";

    
    free(txt); // Free memory used for char array for the text
}

void quit() { 
    cout << "Goodbye!" << endl;
    return;
}


