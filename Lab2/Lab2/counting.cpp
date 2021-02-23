// "/Users/yaroslav/Desktop/Prepar/Lab2_sem2/files/" -> for argument "teka"
//  counting.cpp
#include "counting.hpp"

int stringLength(string s){
    int size = 0;
    while (s[size]){
        size++;
    }
    return size;
}

string nameOfTeam(string line, int length){
    string result = "";
    int ind = 0;
    int counter = 0;
    while ( line[counter] != ',' ) {
        result = result + line[counter];
        counter++;
        ind++;
    }
    return result;
}

int scoreComparising(int scoredGoals, int canceledGoals){
    if (scoredGoals>canceledGoals) {
        return 3;
    }
    else return (scoredGoals<canceledGoals)? 0 : 1;
}









void getMatrix(vector<string> line, int numberOfLines, string *teams, int *ScoreArray){
    for (int i = 0; i < numberOfLines; i++){
        for (int j = 0; j < stringLength(line[i]); j++){
            cout<<line[i][j];
        }
        cout<<endl;
    }
    
    string team[numberOfLines];
    int row = 0;
    int col = 0;
    for (int i = 0; i<numberOfLines; i++){
        team[i] = "";
        while(line[row][col] != ','){
            team[i] = team[i] + line[row][col];
            col++;
        }
        //cout<<col<<endl;
        int goals = 0;
        int cancels = 0;
        int resultedScore = 0;
        for (int j = col; j < stringLength(line[i]); j++){
            if (line[i][j-1] ==',' && line[i][j+1] == ':'){
                goals = int(line[i][j] - 48);
                //cout<<goals<<":";
            }
            if (line[i][j-1] ==':' && (line[i][j+1] == ',' || j+1==stringLength(line[i]))){
                cancels = int(line[i][j] - 48);
                resultedScore = resultedScore+scoreComparising(goals, cancels);
                cout<<i<<"-team "<<resultedScore<<endl;
                //cout<<cancels<<":";
            }
        }
        cout<<"\n";
        ScoreArray[i] = resultedScore;
        row++;
        col=0;
    }

    for (int i = 0; i < numberOfLines; i++){
        teams[i] = nameOfTeam(line[i], stringLength(line[i]));
    }
    
    for (int i=0; i<numberOfLines; i++){
        cout<<teams[i]<<" "<<ScoreArray[i]<<endl;
    }
   
}

