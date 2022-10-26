#include <iostream>
#include <fstream>
#include <chrono>

#include "KMP.cpp"

using namespace std;

int main() {
    //Get file name from user:
    string fileName;
    cout << "Enter the name of the file: " << endl;
    cin >> fileName;
    
    //Open the file:
    fstream myFile;
    myFile.open(fileName);

    //Determine the size of the file
    myFile.seekg(0, ios::end); //final char of .txt file
    unsigned int fileSize = myFile.tellg();
    cout << "\n The size of the file is: " << fileSize << endl;
    char txt[fileSize];

    myFile.close(); //close the file

    //Get the pattern from user:
    char pat[10];
    cout << "The pattern to search for is: " << endl;
    //cin >> pat;
    //cin.getline(pat, 10);
    //unsigned int patSize = pattern.tellg();
    //char pat[] = pattern;

    //Testing outputs: ***DELETE LATER***
    cout << "\n txt[] = " << txt << endl;
    //cout << "\n pat[] = " << pat << endl;

    //CALL SEARCHING FUNCTIONS:
    KMPSearch(pat, txt);



    return 0;
}