//
//  main.cpp
//  Assignment 3
//
//  Created by Brandon Kamplain on 10/25/22.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream in_file("A Scandal in Bohemia.txt", ios::binary);
    in_file.seekg(0, ios::end);
    int file_size = in_file.tellg();
    cout<<"Size of the file is"<<" "<< file_size<<" "<<"bytes";
    return 0;
}
