#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
private:
    vector<string> split(const string& str, char dec)
    {
        int n = str.size();
        int pos = 0, start = 0;
        vector<string> res;
        while (pos < n)
        {
            while (pos < n && str[pos] == dec)
            {
                pos++;
            }
            start = pos;
            while (pos < n && str[pos] != dec)
            {
                pos++;
            }
            if (start < n)
            {
                res.emplace_back(str.substr(start, pos - start));
            }
        }
        return res;
    }

public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        vector<string> strVec = split(text, ' ');
        for (string str : strVec) {
            size_t pos = str.find_last_of(brokenLetters);
            if (pos == std::string::npos) {
                res++;
            }
        }
        return res;
    }
};