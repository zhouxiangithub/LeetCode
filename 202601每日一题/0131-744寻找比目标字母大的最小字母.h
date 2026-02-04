#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char letter : letters) {
            if (letter > target) {
                return letter;
            }
        }
        return letters[0];
    }
};