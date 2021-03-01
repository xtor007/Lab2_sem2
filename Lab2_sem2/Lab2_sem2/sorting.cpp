//
//  sorting.cpp
//  Lab2
//
//  Created by Anatoliy Khramchenko on 2/22/21.
//  Copyright © 2021 Anatoliy Khramchenko. All rights reserved.
//

#include "sorting.hpp"

void replacementInt (int *arr, int a, int b) { //функция для замены в инт массиве
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void replacementString (string *arr, int a, int b) { //функция для замены в стринг массиве
    string c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

bool isMore (int a, int agoals, int adiff, int b, int bgoals, int bdiff) {
    if (a>b) {
        return 1;
    }
    if ((a == b) && (adiff > bdiff)) { //при равенстве очков сравниваем команды по разнице забитых и пропущеных
        return 1;
    }
    if ((a == b) && (adiff == bdiff) && (agoals > bgoals)) { //если же и там равенство то по забитым
        return 1;
    }
    return 0;
}

void sort(int *points, int *diffGoals, int *pGoals, int *pCanc, string *pNames, int staticLeft, int staticRight) {
    if (staticRight > staticLeft) { //для выхода из рекурсии
        int support = points[(staticLeft+staticRight)/2];
        int supportGoals = pGoals[(staticLeft+staticRight)/2];
        int supportDiff = diffGoals[(staticLeft+staticRight)/2]; //создаем опорные елементы
        int left = staticLeft;
        int right = staticRight;
        while (left < right) {
            if (((isMore(support, supportGoals, supportDiff, points[left], pGoals[left], diffGoals[left])) || (left == (staticLeft+staticRight)/2)) &&
                ((isMore(points[right], pGoals[right], diffGoals[right], support, supportGoals, supportDiff)) || (right == (staticLeft+staticRight)/2))) {
                replacementInt(points, left, right); // если левый меньше опорного, а правый больше, то меняем местами
                replacementInt(diffGoals, left, right);
                replacementInt(pGoals, left, right);
                replacementInt(pCanc, left, right);
                replacementString(pNames, left, right);
                left++; right--;
            }
            while ((isMore(points[left], pGoals[left], diffGoals[left], support, supportGoals, supportDiff)) && (left<staticRight)) {
                left++; //увеличуем индекс левого пока не станет меньше опорного
            }
            while ((isMore(support, supportGoals, supportDiff, points[right], pGoals[right], diffGoals[right])) && (right>staticLeft)) {
                right--; //уменьшаем индекс левого пока не станет больше опорного
            }
        }
        sort(points, diffGoals, pGoals, pCanc, pNames, staticLeft, right);
        sort(points, diffGoals, pGoals, pCanc, pNames, right+1, staticRight); //рекурсия
    }
}
