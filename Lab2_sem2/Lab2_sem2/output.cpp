//
//  output.cpp

#include "output.hpp"

void outputInFile(string path, string *teams, int *GoalsArray, int *CancelsArray, int *PointsArray, int size){
    ofstream fileOut;
    fileOut.open(path+"result.csv");
    fileOut<<"#"<<","<<"TEAM"<<","<<setw(2)<<"G"<<","<<"PTS"<<endl;
    if (fileOut.is_open()){
        for(int i = 0; i < size; i++){
            fileOut<<setw(3)<<i+1<<","<<teams[i]<<","<<setw(2)<<GoalsArray[i]<<":"<<CancelsArray[i]<<","<<PointsArray[i]<<endl;
        }
        cout<<"Output was succeeded\n";
        fileOut.close();
    }
    else cout<<"Cannot open the file or it couldn't be created. Try to do it again!\n";

}


