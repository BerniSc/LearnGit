/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

static string data;

vector<vector<string>> linesBernhard;
vector<vector<string>> linesJasmina;

vector<string> singleLinesJasmina;
vector<string> singleLinesBernhard;

static int sumBernhard = 0;
static int sumJasmina = 0;

static int sumBernhardPart2 = 0;
static int sumJasminaPart2 = 0;

void printLines(const vector<vector<string>> &vec, vector<string> &singleLines) {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << endl;
            singleLines.push_back(vec[i][j]);
        }
        cout << endl;
    }    
}

vector<string>& seperateStringTwoParts(string toSeperate, const char *seperator) {
    static vector<string> result;
    char* dataAsPointer = &toSeperate[0];
    char* part1 = strtok(dataAsPointer, seperator);
    result.push_back(part1);
    char* part2 = strtok(NULL, seperator);
    result.push_back(part2);
    
    return result;
}

void processData(const vector<string> &vecSingle) {

}

int main() {
    ifstream myfileB, myfileJ;
    
    myfileB.open("bernhard.txt");
    
    vector<string> paragraph;
    
    if(myfileB.is_open()) {
        while(myfileB) {
            if(myfileB.eof()) data = "";
            getline(myfileB, data);
            if(data != "") {
                paragraph.push_back(data);
            } else {
                linesBernhard.push_back(paragraph);
                paragraph.clear();
            }
        }
    }
    printLines(linesBernhard, singleLinesBernhard);
    processData(singleLinesBernhard);

    myfileJ.open("jasmina.txt");
    
    if(myfileJ.is_open()) {
        while(myfileJ) {
            if(myfileJ.eof()) data = "";
            getline(myfileJ, data);
            if(data != "") {
                paragraph.push_back(data);
            } else {
                linesJasmina.push_back(paragraph);
                paragraph.clear();
            }
        }
    }

    printLines(linesJasmina, singleLinesJasmina);
    processData(singleLinesJasmina);
    
    cout << endl << "Bernhard: " << sumBernhard <<  "   " << sumBernhardPart2 << endl;
    cout << "Jasmina: " << sumJasmina << "  " << sumJasminaPart2 << endl;

    return 0;
}
