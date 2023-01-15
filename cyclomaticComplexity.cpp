#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <algorithm>
#include <cctype>
#define KEY_VALUE 50


using namespace std;
ifstream Code;
string rowOfCode;
string KEYS[KEY_VALUE] = {"if(","while(","for(","?", "&&","||"};

int main(){
Code.open("temp.txt");
while(!Code.eof()){
    getline(Code, rowOfCode, '\n'); // use ' ' as separator, default is '\n' (newline). Now name is "John".
    rowOfCode.erase(remove_if(rowOfCode.begin(), rowOfCode.end(), ::isspace), rowOfCode.end());
cout << rowOfCode << endl; 

   /* for(int i = 0;i<rowOfCode.length();i++){
        for(int j = 0;j<sizeof(KEYS);j++){
            if(KEYS[j][0] == rowOfCode[i]){
                
            }
        }
    }*/
}

  

Code.close(); 
}
