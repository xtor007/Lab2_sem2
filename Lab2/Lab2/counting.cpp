// "/Users/yaroslav/Desktop/Prepar/Lab2_sem2/files/" -> for argument "teka"
//  counting.cpp
#include "counting.hpp"


string nameOfTeam(string line, int length, int &index){
    string result = "";
    index = 0;
    while ( line[index] != ',' ) {
        result = result + line[index];
        index++;
    }
    return result;
}

int scoreComparising(int scoredGoals, int canceledGoals){
    if (scoredGoals>canceledGoals) {
        return 3;
    }
    else return (scoredGoals<canceledGoals)? 0 : 1;
}

int* getScore(vector<string> line, int numberOfLines, string *teams, int *GoalsArray, int *differenceArray, int *CancelsArray){
    
    int ResultedScoreArray[numberOfLines];
    int row = 0;
    int col = 0;
    int goals = 0;
    int cancels = 0;
    
    for (int i = 0; i<numberOfLines; i++){
        
        teams[i] = nameOfTeam(line[i], line[i].size(), col);
        ResultedScoreArray[i] = 0;
        GoalsArray[i] = 0;
        CancelsArray[i] = 0;
        differenceArray[i] = 0;
        int resultedScore = 0;
        
        for (int j = col; j < line[i].size(); j++){
            if (line[i][j-1] ==',' && line[i][j+1] == ':'){
                goals = int(line[i][j] - 48);
                GoalsArray[i] = GoalsArray[i] + goals;
                //cout<<goals<<":";
            }
            if (line[i][j-1] ==':' && (line[i][j+1] == ',' || j+1==line[i].size())){
                cancels = int(line[i][j] - 48);
                CancelsArray[i] = CancelsArray[i] + cancels;
                ResultedScoreArray[i] = ResultedScoreArray[i] + scoreComparising(goals, cancels);
                cout<<i<<"-team "<<resultedScore<<endl;
            }
        }
        differenceArray[i] = GoalsArray[i] - CancelsArray[i];
        row++;
        col=0;
    }
    return ResultedScoreArray;
}

