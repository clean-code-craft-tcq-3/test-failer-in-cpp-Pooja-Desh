#include <iostream>
#include <assert.h>
#include <vector>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
int numberOfMajorColor = sizeof(majorColor)/sizeof(majorColor[0]);
int numberOfMinorColor = sizeof(minorColor)/sizeof(minorColor[0]);
int maxNumberofColorPairs = numberOfMajorColor * numberOfMinorColor;
    
int lengthOflongestMajorColor = 0;
int formatCounterStub = 0;
int printCounterStub = 0;

//std::vector<std::string> colorMap[maxNumberofColorPairs] = {""};

std::string getColorPair(int majorColorNumber,int minorColorNumber)
{
    std::string colorPairString = "";
    return colorPairString.append(majorColor[minorColorNumber]).append("|").append(minorColor[majorColorNumber]);
}

std::vector<std::string> generateColorPairMap(std::vector<std::string> colorMap)
{
    //std::string colorMap[maxNumberofColorPairs] = {""};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::string receivedColorPair = getColorPair(i,j);
            colorMap[(i * 5 + j)] = receivedColorPair;
        }
    }
    return(colorMap);
}

int printColorMap(std::vector<std::string> colorMap)
{   
    int i;
    std::vector<std::string> generatedColorMap = generateColorPairMap(colorMap);
    for(i = 0; i < maxNumberofColorPairs; i++) 
    {
        std::cout<<(i+1)<<" | "<< generatedColorMap[i]<<"\n";
    }
    return(i);
}

int main() 
{
    std::vector<std::string> testColorMap;
    int result = printColorMap(testColorMap);
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    
    assert(testColorMap[1] == "WHITE | BLUE"); 
    assert(testColorMap[2] == "WHITE | ORANGE"); 
    return 0;
}
