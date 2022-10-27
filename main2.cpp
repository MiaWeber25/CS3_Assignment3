#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>

#include "KMP.cpp"
#include "Horspool.cpp"
//https://stackoverflow.com/questions/30696639/increase-the-maximum-size-of-char-array 

using namespace std;

int main() {
    //Get file name from user:
    string fileName;
    cout << "Please specify input text file name: " << endl;
    getline(cin, fileName);

    //TESTING:
    cout << "Text File name: " << fileName << endl;
    
    //Open the file:
    fstream myFile;
    myFile.open(fileName);
    cout << "OPENED THE FILE" << endl;
    //Determine the size of the file
    myFile.seekg(0, ios::end); //final char of .txt file
    unsigned int fileSize = myFile.tellg();

    cout << "\n The size of the file is: " << fileSize << endl;
    cout << "ABOUT TO CREATE THE TEXT ARRAY" << endl;
    //char txt[fileSize]; //WORKS BUT SEG FAULTS HERE
    char * txt;
    txt = (char*) malloc (100*sizeof(char));
    if (txt==NULL) exit (1);

    //char * pat;
    //pat = (char*) malloc (100*sizeof(char));
    //if (pat==NULL) exit (1);
    //cin >> input;
    /*char * pat;
    pat = (char*) malloc (100*sizeof(char));
    if (pat==NULL) exit (1);*/
    char pat[100];

    //string patInput;
    cout << "enter pattern: " << endl;
    //cin.ignore();
    cin.getline(pat, 100);
    cout << "pat[] = " << pat << endl;
    







    //start the clock:
    //chrono::high_resolution_clock::time_point firstTime;
    auto start = chrono::high_resolution_clock::now();
    myFile.seekg(0,ios::beg);
	myFile.read(txt, fileSize); //SHERINE CODE
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);
    cout << "Text read! Time to read: " << duration.count() << " nanoseconds" << endl;
    myFile.close(); //close the file

  
    //cout << "\n txt[] = " << txt << endl;
    //cout << "\n pat[] = " << pat << endl;
	//char pat[] = "eBook";
    //char pat[] = "The Mall.";
    //CALL SEARCHING FUNCTIONS:
    cout << "CALLING KMP SEARCH FUNCTION..." << endl;
    KMPSearch(pat, txt);
    cout << "AFTER KMP SEARCH CALL" << endl;
    
    cout << "CALLING HORSPOOL SEARCH FUNCTION..." << endl;
    HorspoolMatching(pat, txt);
    cout << "AFTER HORSPOOL SEARCH CALL" << endl;

    free(txt);
    return 0;
}