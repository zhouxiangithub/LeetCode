#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (string& detail : details)
        {
            if (stoi(detail.substr(11, 2)) > 60)
            {
                res++;
            }
        }
        return res;
    }
};