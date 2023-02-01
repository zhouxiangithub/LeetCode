#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> map;
        int n = num.size();
        for (int i = 0; i < n; i++)
        {
            map[num[i] - '0']++;
        }
        for (int i = 0; i < n; i++)
        {
            if (map[i] != (num[i] - '0'))
            {
                return false;
            }
        }
        return true;
    }
};