/*
	Assignment 3 Driver Code
	CSCI 250 Mia Weber & Brandon Kamplain
	10/30/2022
    Useful resources: https://stackoverflow.com/questions/30696639/increase-the-maximum-size-of-char-array 
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

// function prototypes:
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

void menu(int input) { // print menu for user
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

void search() { // logic to call searching algorithms
    // Get file name from user:
    string fileName;
    cout << "Please specify input text file name: " << endl;
    cin.ignore();
    getline(cin, fileName);

    // TESTING: ***DELETE LATER***
    cout << "Text File name: " << fileName << endl;
    
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
    char pat[100]; // ***NEED TO CHANGE 100***
    cout << "enter pattern: " << endl;
    cin.getline(pat, 100); // ***NEED TO CHANGE 100***
    cout << "pat[] = " << pat << endl;
    

    // Start the clock:
    auto start = high_resolution_clock::now();
    myFile.seekg(0,ios::beg);
	myFile.read(txt, fileSize); // Read the file
    //Stop the clock:
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    cout << "Text read! Time to read: " << duration.count() << " milliseconds\n" << endl;
    myFile.close(); // Close the file

    // Call search functions:
    cout << "KMP:\n";
    start = high_resolution_clock::now();
    //KMP(pat, txt);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop-start);
    cout << "Time: " << duration.count() << " milliseconds\n";

    cout << "\nHorspool:\n";
    start = high_resolution_clock::now();
    HorspoolMatching(pat, txt); //Horspool
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop-start);
    cout << "Time: " << duration.count() << " milliseconds\n";
    
    //Karp Rabin
    cout << "\nKarp-Rabin:\n";
    start = high_resolution_clock::now();
    //calculate q (large prime number)
    int q = INT_MAX;
    //search(pat, txt, q);
    KRMatching(pat, txt, q);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop-start);
    cout << "Time: " << duration.count() << " milliseconds" << endl;


    free(txt); //Free memory used for char array for the text
}

void quit() { 
    cout << "Goodbye!" << endl;
    return;
}

