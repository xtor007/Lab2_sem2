//
//  reading.cpp
//  Lab2
//
//  Created by Anatoliy Khramchenko on 2/22/21.
//  Copyright © 2021 Anatoliy Khramchenko. All rights reserved.
//

#include "reading.hpp"

vector<string> readFiles(int *kolTeams) {
    kolTeams = 0;
    string teka;
    cin >> teka;
    teka += "premier_league";
    vector<string> resultRead;
    int countFiles = 1;
    string nowFile = teka + to_string(countFiles) + ".csv";
    string s;
    int countTeamInFile;
    ifstream inFile;
    inFile.open(nowFile);
    while (inFile.is_open()) {
        getline(inFile,s,'\0');
        countTeamInFile = stoi(s);
        for (kolTeams; kolTeams<kolTeams+countTeamInFile; kolTeams++) {
            getline(inFile,s,'\0');
            resultRead.push_back(s);
        }
    }
//    /Users/khramchenko/Documents/Lab2_sem2/files/premier_league2.csv
    return resultRead;
}
