#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char letter : letters)
        {
            if (letter > target)
            {
                return letter;
            }
        }
        return letters[0];
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        return target < letters.back() ? *upper_bound(letters.begin(), letters.end() - 1, target) : letters[0];
    }
};