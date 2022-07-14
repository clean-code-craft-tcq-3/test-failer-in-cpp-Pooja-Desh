#include <iostream>
#include <assert.h>

struct
    {
        int colorPairID;
        char* majorColorName;
        char* minorColorName;
    }colorPair;
colorPair[25] ={};

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            int colorPairID = i * 5 + j ;
            colorPair[colorPairID] = {colorPairID,majorColor[i],majorColor[i]};
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            colorPairID = i * 5 + j;
            assert(colorPair[colorPairID].minorColorName == minorColor[j]);
        }
    }
            
    return 0;
}
