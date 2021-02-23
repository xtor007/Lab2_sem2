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
    string teams[n];
    int cancels[n];
    int difference[n];
    int goals[n];
    int array[n];
    getScore(mtx, n, teams, goals, difference, cancels, array);
    sort(array, difference, goals, cancels, teams, n);
    outputInFile(path, teams, goals, difference, array, n);
    return 0;
}
