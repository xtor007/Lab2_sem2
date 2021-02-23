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
    int n = 0;
    vector<string> mtx;
    mtx = readFiles(&n);
    string teams[n];
    int cancels[n];
    int difference[n];
    int goals[n];
    int array[n];
    for(int i = 0; i<n; i++){
        array[i] = getScore(mtx, n, teams, goals, difference, cancels)[i];
    }
    return 0;
}
