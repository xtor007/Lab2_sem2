//
//  reading.cpp
//  Lab2
//
//  Created by Anatoliy Khramchenko on 2/22/21.
//  Copyright © 2021 Anatoliy Khramchenko. All rights reserved.
//

#include "reading.hpp"

vector<string> readFiles(string &path, int *kolTeams) {
    *kolTeams = 0;
    int nn = *kolTeams;
    string teka;
    getline(cin,teka); //считывание теки
    path = teka;
    teka += "premier_league";
    vector<string> resultRead;
    int countFiles = 1;
    string nowFile = teka + to_string(countFiles) + ".csv"; //создаем адресс файла
    string s; //дополнительня строковая переменная
    int countTeamInFile;
    ifstream inFile;
    inFile.open(nowFile);
    while (inFile.is_open()) {
        getline(inFile,s,'\n');
        countTeamInFile = stoi(s); //считуем количество команд в файле и преобразуем в число
        for (nn = *kolTeams; nn<*kolTeams+countTeamInFile; nn++) { //считываем строки
            getline(inFile,s,'\n');
            resultRead.push_back(s);
        }
        *kolTeams = nn;
        countFiles++;
        nowFile = teka + to_string(countFiles) + ".csv"; //обновляем адрес файла
        inFile.close();
        inFile.open(nowFile); //закрываем старый и открываем новый файл
    }
//    /Users/khramchenko/Documents/Lab2_sem2/files/premier_league2.csv
    inFile.close();
    return resultRead;
}
