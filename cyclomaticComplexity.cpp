#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <algorithm>
#include <cctype>

#define KEY_VALUE 6
#define STRING_SIZE 32
bool FoundKey = false;
using namespace std;
ifstream Code;
string rowOfCode;
string KEYS[KEY_VALUE] = {"if(","while(","for(","?", "&&","||"};
int cyclomaticComplexityVal = 0;
int main(){

Code.open("temp.txt"); // open the txt

while(!Code.eof()){
    getline(Code, rowOfCode, '\n'); // dosyadaki her bir line ı al
    rowOfCode.erase(remove_if(rowOfCode.begin(), rowOfCode.end(), ::isspace), rowOfCode.end()); // satırdaki boşlukları sil
    //cout << rowOfCode << endl; 

   for(int rowIterator = 0;rowIterator<rowOfCode.length();rowIterator++){ // kelimenin i. harfi
        for(int keysIterator = 0;keysIterator<sizeof(KEYS)/STRING_SIZE;keysIterator++){
            if(FoundKey == true){ // eğerki halihazırda bir yapı bulduysak (kelimeyi karşılaştırmaya devam etmesin)
                FoundKey = false;
                break;
                } 
            if(KEYS[keysIterator][0] == rowOfCode[rowIterator]){
                if(KEYS[keysIterator][0] == KEYS[3][0]){ // soru işaretini tanımıyor tek karakter olduğundan. o yüzden böyle bir koşul yazdım
                    cyclomaticComplexityVal++;
                    break;
                }
                
            int rowIteratorForKeyTest = rowIterator+1; 
            for(int letterOfKeyIterator = 1;letterOfKeyIterator<KEYS[keysIterator].length();letterOfKeyIterator++){ 
                if(KEYS[keysIterator][letterOfKeyIterator] == rowOfCode[rowIteratorForKeyTest]){// keys in keysIterator. elemanının k. harfi de rowOfCode'nin devamıyla eşleşiyorsa
                    
                    if(letterOfKeyIterator == KEYS[keysIterator].length()-1 && KEYS[keysIterator].at(KEYS[keysIterator].length()-1) == rowOfCode[rowIteratorForKeyTest]){ // artık kelimenin son harfi de eşleşmeye devam ediyorsa
                        cyclomaticComplexityVal++;
                        rowIterator = rowIteratorForKeyTest+1;
                        FoundKey = true;
                        break;
                    }
                    rowIteratorForKeyTest++;

                    }
                    else{break;
                    }
                }
            }
            
        }
    }
}

cyclomaticComplexityVal = cyclomaticComplexityVal+1; // formülden ötürü
cout << cyclomaticComplexityVal << endl;

Code.close(); 
}
