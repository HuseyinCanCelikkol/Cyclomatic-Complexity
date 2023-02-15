let LANGUAGE_COUNT = 6
let KEY_SIZE = 8
let STRING_SIZE = 32

let FoundKey = false;
let trimmedLine;
//console.log("okay 1 ")

let CPP_KEYS = ["if(","while(","for(","?", "&&","||","case","default:"];
//console.log(CPP_KEYS);
//console.log("okay 2");

let cyclomaticComplexityVal = 0;
let CodeLineVal = 0;

// file opening
const fs = require("fs");

fs.open("temp.txt", "r", (err, file) => {
   if (err) throw err;
   console.log(file);
});
// holds lines in each element.
let codeLines = fs.readFileSync('temp.txt').toString().split("\n");


console.log("okay 3");
let lineIterator = -1;


while(codeLines[codeLines.length - 1] !== codeLines[lineIterator]){ // eof (kill me)
    lineIterator++;
    let trimmedLine = codeLines[lineIterator].replaceAll(" ", "");
    //console.log(trimmedLine);
    // on the upwards, it just deletes spaces and takes lines.
    for(let rowIterator = 0;rowIterator<trimmedLine.length;rowIterator++){ // i'th letter of row
        for(let keysIterator = 0;keysIterator<CPP_KEYS.length;keysIterator++){
            if(FoundKey == true){ // if we found a key, it shouldn't continue to inspect current key. instead, it need to go find another one.
                FoundKey = false;
                break;
                } 
            if(CPP_KEYS[keysIterator][0] == trimmedLine[rowIterator]){// if that keys first letter hits with current letter
                if(CPP_KEYS[keysIterator][0] == CPP_KEYS[3][0]){ // it cannot find ? operator. thats why i used that condition
                    cyclomaticComplexityVal++;
                    break;
                }
                
                
            let tempRowIterator = rowIterator+1; // temp row iterator. If it finds a key, simply goes afterwards of found key.
            for(let letterOfKeyIterator = 1;letterOfKeyIterator<CPP_KEYS[keysIterator].length;letterOfKeyIterator++){ // here we controlling key and letter if really meshes together
                if(CPP_KEYS[keysIterator][letterOfKeyIterator] == trimmedLine[tempRowIterator]){// if continues to mesh, just control until end
                    
                    if(letterOfKeyIterator == CPP_KEYS[keysIterator].length-1 && CPP_KEYS[keysIterator].at(CPP_KEYS[keysIterator].length-1) == trimmedLine[tempRowIterator]){ // if last letter also meshes
                    if(keysIterator==6){
                        for(let i = 0;i<trimmedLine.length-tempRowIterator;i++){
                            if(trimmedLine[tempRowIterator+i] == ':'){ // if finds : in same row after finding "case", it increases complexity +1.
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
console.log("cyclomatic complexity is :" + cyclomaticComplexityVal) // thats the value
console.log("code length is: " + lineIterator);