#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<string> getPos(string s)
    {
        vector<string> pos;
        if (s[0] != '0' || s == "0")
        {
            pos.push_back(s);
        }
        for (int len = 1; len < s.size(); len++)
        {
            if ((len != 1 && s[0] == '0') || s.back() == '0')
            {
                continue;
            }
            pos.push_back(s.substr(0, len) + "." + s.substr(len));
        }
        return pos;
    }

    vector<string> ambiguousCoordinates(string s) {
        int n = s.size() - 2;
        vector<string> res;
        s = s.substr(1, n);
        for (int len = 1; len < n; len++)
        {
            vector<string> left = getPos(s.substr(0, len));
            if (left.empty())
            {
                continue;
            }
            vector<string> right = getPos(s.substr(len));
            if (right.empty())
            {
                continue;
            }
            for (auto& i : left)
            {
                for (auto& j : right)
                {
                    res.push_back("(" + i + ", " + j + ")");
                }
            }
        }
        return res;
    }
};