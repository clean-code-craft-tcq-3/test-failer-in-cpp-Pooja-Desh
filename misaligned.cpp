#include <iostream>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
int numberOfMajorColor = sizeof(majorColor)/sizeof(majorColor[0]);
int numberOfMinorColor = sizeof(minorColor)/sizeof(minorColor[0]);
int maxNumberofColorPairs = numberOfMajorColor * numberOfMinorColor;
    
int lengthOflongestMajorColor = 0;
int formatCounterStub = 0;
int printCounterStub = 0;

int printColorMap() {
    
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
            
    return 0;
}
