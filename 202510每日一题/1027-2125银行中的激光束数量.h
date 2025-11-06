#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, last = 0;
        for (const string& line : bank) {
            int cnt = count_if(line.begin(), line.end(), [](char ch) {return ch == '1'; });
            if (cnt != 0) {
                res += cnt * last;
                last = cnt;
            }
        }
        return res;
    }
};