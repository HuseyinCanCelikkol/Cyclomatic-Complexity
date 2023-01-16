#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <algorithm>
#include <cctype>

#define KEY_VALUE 8
#define STRING_SIZE 32
bool FoundKey = false;
using namespace std;
ifstream Code;
string rowOfCode;
string KEYS[KEY_VALUE] = {"if(","while(","for(","?", "&&","||","case","default:"};

int cyclomaticComplexityVal = 0;
int main(){

Code.open("temp.txt"); // open the txt

while(!Code.eof()){
    getline(Code, rowOfCode, '\n'); // take each line on temp.txt
    rowOfCode.erase(remove_if(rowOfCode.begin(), rowOfCode.end(), ::isspace), rowOfCode.end()); // delete whitespaces
    //cout << rowOfCode << endl; //for printing your code

   for(int rowIterator = 0;rowIterator<rowOfCode.length();rowIterator++){ // i'th letter of row
        for(int keysIterator = 0;keysIterator<sizeof(KEYS)/STRING_SIZE;keysIterator++){
            if(FoundKey == true){ // if we found a key, it shouldn't continue to inspect current key. instead, it need to go find another one.
                FoundKey = false;
                break;
                } 
            if(KEYS[keysIterator][0] == rowOfCode[rowIterator]){// if that keys first letter hits with current letter
                if(KEYS[keysIterator][0] == KEYS[3][0]){ // it cannot find ? operator. thats why i used that condition
                    cyclomaticComplexityVal++;
                    break;
                }
                
                
            int tempRowIterator = rowIterator+1; // temp row iterator. If it finds a key, simply goes afterwards of found key.
            for(int letterOfKeyIterator = 1;letterOfKeyIterator<KEYS[keysIterator].length();letterOfKeyIterator++){ // here we controlling key and letter if really meshes together
                if(KEYS[keysIterator][letterOfKeyIterator] == rowOfCode[tempRowIterator]){// if continues to mesh, just control until end
                    
                    if(letterOfKeyIterator == KEYS[keysIterator].length()-1 && KEYS[keysIterator].at(KEYS[keysIterator].length()-1) == rowOfCode[tempRowIterator]){ // if last letter also meshes
                    if(keysIterator==6){
                        for(int i = 0;i<rowOfCode.length()-tempRowIterator;i++){
                            if(rowOfCode[tempRowIterator+i] == ':'){
                        cyclomaticComplexityVal++; // increase complexity value
                        rowIterator = tempRowIterator+1;// continue from afterwards of found key
                        FoundKey = true; // yeah that's what you're searching for. if i don't put that condition it continues to iterate keys. I and nobody don't want that
                        break;
                            }
                        }
                    }
                    else{
                        cyclomaticComplexityVal++; // increase complexity value
                        rowIterator = tempRowIterator+1;// continue from afterwards of found key
                        FoundKey = true; // yeah that's what you're searching for. if i don't put that condition it continues to iterate keys. I and nobody don't want that
                        break; // go out from letter iteration
                        }
                    }
                    tempRowIterator++;

                    }
                    else{break; // if any of letter doesn't obey order, just break and go 
                    }
                }
            }
            
        }
    }
}

cyclomaticComplexityVal = cyclomaticComplexityVal+1; // formula = found complexity + 1 
cout << cyclomaticComplexityVal << endl; // thats the value

Code.close(); // dont forget to close directory...
}
