#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    static bool myCompare(string& log1, string& log2)
    {
        int index1 = log1.find_first_of(' ');
        int index2 = log2.find_first_of(' ');
        if (log1.substr(index1 + 1) != log2.substr(index2 + 1))
        {
            return log1.substr(index1 + 1) < log2.substr(index2 + 1);
        }
        return log1 < log2;
        
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        if (logs.size() <= 1)
        {
            return logs;
        }
        vector<string> res, digitVec;
        for (int i = 0; i < logs.size(); i++)
        {
            int index = logs[i].find_first_of(' ');
            if (logs[i][index + 1] >= '0' && logs[i][index + 1] <= '9')
            {
                digitVec.emplace_back(logs[i]);
            }
            else
            {
                res.emplace_back(logs[i]);
            }
        }
        sort(res.begin(), res.end(), myCompare);
        res.insert(res.end(), digitVec.begin(), digitVec.end());
        return res;
    }
};