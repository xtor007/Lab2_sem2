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

void sort(int *points, int *diffGoals, int *pGoals, int *pCanc, string *pNames, int staticLeft, int staticRight) {
    if (staticRight > staticLeft) {
        int support = points[(staticLeft+staticRight)/2];
        //int support = (staticLeft+staticRight)/2;
        int left = staticLeft;
        int right = staticRight;
        while (left < right) {
            if (((points[left]<support) || (left == (staticLeft+staticRight)/2)) && ((points[right]>support) || (right == (staticLeft+staticRight)/2))) {
                replacementInt(points, left, right);
                replacementInt(diffGoals, left, right);
                replacementInt(pGoals, left, right);
                replacementInt(pCanc, left, right);
                replacementString(pNames, left, right);
            }
            while (((points[left]>support) && (left<staticRight)) || (left==(staticLeft+staticRight)/2)) {
                left++;
            }
            while (((points[right]<support) && (right>staticLeft)) || (right==(staticLeft+staticRight)/2)) {
                right--;
            }
        }
        sort(points, diffGoals, pGoals, pCanc, pNames, staticLeft, right);
        sort(points, diffGoals, pGoals, pCanc, pNames, right+1, staticRight);
    }
}
