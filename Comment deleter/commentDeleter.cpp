#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <algorithm>
#include <cctype>
using namespace std;
string rowOfCode;
ifstream Code;
ofstream MyFile("CodeWithoutComments.txt");
int main(){
    Code.open("code.txt");
    while(!Code.eof()){
        getline(Code, rowOfCode, '\n');
       // rowOfCode.erase(remove_if(rowOfCode.begin(), rowOfCode.end(), ::isspace), rowOfCode.end()); //deletes whitespaces 
        for(int i = 0;i<rowOfCode.length();i++){
            if(rowOfCode[i] == '/' && rowOfCode[i+1] == '/'){
                rowOfCode.erase(rowOfCode.begin()+i, rowOfCode.end());
            }
            else if(rowOfCode[i] == '/' && rowOfCode[i+1] == '*'){
                rowOfCode.erase(rowOfCode.begin()+i,rowOfCode.end());
                bool multiCommLine = true;
                while(multiCommLine){
                    getline(Code, rowOfCode, '\n');
                    //cout << rowOfCode << endl; // for debug
                    for(int j = 0;j<rowOfCode.length();j++){
                        if(rowOfCode[j] == '*' && rowOfCode[j+1] == '/'){
                            rowOfCode.erase(rowOfCode.begin(),rowOfCode.begin()+(j+2));
                            multiCommLine = false;
                        }
                        else if(j == rowOfCode.length() -1){
                            rowOfCode.erase(rowOfCode.begin(),rowOfCode.end());
                        }
                    }
                }
            }
        }
        cout << rowOfCode << endl;
        MyFile << rowOfCode << endl;
    }
    
}