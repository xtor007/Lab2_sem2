//
//  output.cpp

#include "output.hpp"

void outputInFile(string *teams, int *GoalsArray, int *CancelsArray, int *PointsArray, int size){
    ofstream fileOut;
    fileOut.open("/Users/yaroslav/Desktop/Prepar/Lab2_sem2/files/result.csv");
    if (fileOut.is_open()){
        for(int i = 0; i < size; i++){
            fileOut<<i<<". "<<teams[i]<<" - "<<GoalsArray[i]<<":"<<CancelsArray[i]<<"     "<<PointsArray[i]<<endl;
        }
    }
    else cout<<"Cannot open the file or it couldn't be created. Try to do it again!\n";

}


