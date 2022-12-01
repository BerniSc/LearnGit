/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static string data;

vector<vector<string>> lines;

void printLines(const vector<vector<string>> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << endl;
        }
        cout << endl;
    }    
}

void processData(vector<vector<string>> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        int sumRow = 0;
        for(int j = 0; j < vec[i].size(); j++) {
           sumRow += stoi(vec[i][j]); 
        }
        cout << "   " << sumRow << endl;
    } 
}

int main() {
    ifstream myfile;
    
    myfile.open("data.txt");
    
    vector<string> paragraph;
    
    if(myfile.is_open()) {
        while(myfile) {
            if(myfile.eof()) data = "";
            getline(myfile, data);
            if(data != "") {
                paragraph.push_back(data);
            } else {
                lines.push_back(paragraph);
                paragraph.clear();
            }
        }
    }
    printLines(lines);
    processData(lines);

    return 0;
}
