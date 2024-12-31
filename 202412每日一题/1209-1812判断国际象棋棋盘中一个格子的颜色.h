#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a' + 1) + (coordinates[1] - '0')) % 2 == 1;
    }
};