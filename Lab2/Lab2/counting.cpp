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
