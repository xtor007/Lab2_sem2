//
//  main.cpp
//  Lab2
//
//  Created by Anatoliy Khramchenko on 2/20/21.
//  Copyright © 2021 Anatoliy Khramchenko. All rights reserved.
//

#include <iostream>
#include <vector>
#include "reading.hpp"
#include "counting.hpp"
#include "sorting.hpp"
#include "output.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int n = 0;               // number of teams in sources
    cout<<"Write in a path to the directory with your files\n";
    vector<string> mtx;
    string path;             // path to the directory with sources
    mtx = readFiles(path, &n);
    
    string teams[n];         //names of teams
    int cancels[n];          //numbers of canceled balls for each team
    int difference[n];       //numbers of difference between canceled balls and goals(for case when num of                          points from one team is equal to num of points from another team
    int goals[n];            //numbers of goals for each team
    int array[n];           //points for each team
    
    getScore(mtx, n, teams, goals, difference, cancels, array);    // a func for getting array of points
    sort(array, difference, goals, cancels, teams, n);
    outputInFile(path, teams, goals, cancels, array, n);        // outputing sorted arrays in file
    return 0;
}
