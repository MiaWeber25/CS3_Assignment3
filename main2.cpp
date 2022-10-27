#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>

#include "KMP.cpp"
#include "Horspool.cpp"
//https://stackoverflow.com/questions/30696639/increase-the-maximum-size-of-char-array 

using namespace std;
void search();
void quit();
void menu(int);

int main() {
    //S for search Q for quit -> switch statement:
    char input = 'S';
    while (input == 'S') {
        cout << "Welcome! Please enter 'S' for search and 'Q' for quit: " << endl;
        //cin.ignore();
        cin >> input;
        menu(input);
    }  
}

void menu(int input) {
    switch(input) {
        case 'S': {//Search was selected
            search();
            break;
        }
        case 'Q': {//Quit was selected
            quit();
            break;
        }
    }
}

void search() {
    //Get file name from user:
    string fileName;
    cout << "Please specify input text file name: " << endl;
    cin.ignore();
    getline(cin, fileName);

    //TESTING:
    cout << "Text File name: " << fileName << endl;
    
    //Open the file:
    fstream myFile;
    myFile.open(fileName);

    //Determine the size of the file:
    myFile.seekg(0, ios::end); //final char of .txt file
    unsigned int fileSize = myFile.tellg();

    //TESTING:
    cout << "\n The size of the file is: " << fileSize << endl;

    //Create the char array to store the text from the file:
    char * txt;
    txt = (char*) malloc (100*sizeof(char));
    if (txt==NULL) exit (1);

    //Get the pattern from the user:
    char pat[100]; //NEED TO CHANGE 100
    cout << "enter pattern: " << endl;
    cin.getline(pat, 100); //NEED TO CHANGE 100
    cout << "pat[] = " << pat << endl;
    

    //start the clock:
    auto start = chrono::high_resolution_clock::now();
    myFile.seekg(0,ios::beg);
	myFile.read(txt, fileSize); //Read the file
    //stop the clock:
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);
    cout << "Text read! Time to read: " << duration.count() << " nanoseconds\n" << endl;
    myFile.close(); //close the file

    //Call search functions:
    cout << "KMP:\n";
    start = chrono::high_resolution_clock::now();
    KMPSearch(pat, txt); //KMP
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);
    cout << "Time: " << duration.count() << " nanoseconds\n";

    cout << "\nHorspool:\n";
    start = chrono::high_resolution_clock::now();
    HorspoolMatching(pat, txt); //Horspool
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);
    cout << "Time: " << duration.count() << " nanoseconds\n";
    
    //Karp Rabin

    free(txt); //Free memory used for char array for the text
}

void quit() {
    cout << "Goodbye!" << endl;
    return;
}