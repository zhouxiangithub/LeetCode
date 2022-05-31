#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> rows(numRows);
        int flag = 1; //转向标志
        int idxRows = 0; //行下标索引
        for (int i = 0; i < s.size(); i++)
        {
            rows[idxRows].push_back(s[i]);
            idxRows += flag;
            if (idxRows == numRows - 1 || idxRows == 0)
            {
                flag = -flag;
            }
        }
        string res;
        for (auto row : rows)
        {
            res += row;
        }
        return res;
    }
};