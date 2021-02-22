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
    string s[20];
    int score[20];
    getMatrix(mtx, n, s, score);
    /*
    for (int i = 0; i<n; i++){
        cout<<mtx[i]<<"     "<< stringLength(mtx[i])<<endl;
    }
    cout<<endl<<endl;
    */
    for (int i = 0; i<20; i++){
        cout<<s[i]<<" "<<score[i]<<endl;
    }
    return 0;
}
