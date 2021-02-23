//
//  output.cpp

#include "output.hpp"

void outputInFile(string *teams, int *GoalsArray, int *CancelsArray, int *PointsArray){
    ofstream fileOut;
    fileOut.open("/Users/yaroslav/Desktop/Prepar/Lab2_sem2/files/result.csv");
    if (fileOut.is_open()){
        
    }
    else cout<<"Cannot open the file or it couldn't be created. Try to do it again!\n";

}


