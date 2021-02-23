//
//  sorting.cpp
//  Lab2
//
//  Created by Anatoliy Khramchenko on 2/22/21.
//  Copyright © 2021 Anatoliy Khramchenko. All rights reserved.
//

#include "sorting.hpp"

void replacementInt (int *arr, int a, int b) {
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void replacementString (string *arr, int a, int b) {
    string c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void sort(int *points, int *diffGoals, int *pGoals, string *pNames, int numberOfTeams) {
    int pivot = numberOfTeams - 1;
    int wall = 0;
    int currentValue = 0;
    while (pivot >= 1) {
        wall = 0;
        currentValue = 0;
        while (currentValue < pivot) {
            if (points[currentValue]>points[pivot]) {
                
            }
        }
        pivot--;
    }
}
