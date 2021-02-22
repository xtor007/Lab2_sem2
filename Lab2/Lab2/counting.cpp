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

void getMatrix(vector<string> line, int numberOfLines){
    string teams[numberOfLines];
    bool flag = 1;
    // initialization of matrix for each team's score
    // number of rows obviously will be equal to a number of teams(defolt: 20)
    // number of columns will be equal to 2, cause for each command we have 2 values: number of canceled goals and number of scored goals
    
    int **matrixScore = new int *[numberOfLines];
    for (int i = 0; i < numberOfLines; i++){
        matrixScore[i] = new int[2];
    }
    
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

    }

    for (int i = 0; i < numberOfLines; i++){
        teams[i] = nameOfTeam(line[i], stringLength(line[i]));
    }
    
    for (int i=0; i<numberOfLines; i++){
        cout<<teams[i]<<endl;
    }
   
}
}
