#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string line = "";
        bool isComment = false;
        for (auto& src : source)
        {
            for (int i = 0; i < src.size(); i++)
            {
                if (isComment)
                {
                    if (i + 1 < src.size() && src[i] == '*' && src[i + 1] == '/')
                    {
                        isComment = false;
                        i++;
                    }
                }
                else
                {
                    if (i + 1 < src.size() && src[i] == '/' && src[i + 1] == '*')
                    {
                        isComment = true;
                        i++;
                    }
                    else if (i + 1 < src.size() && src[i] == '/' && src[i + 1] == '/')
                    {
                        break;
                    }
                    else
                    {
                        line += src[i];
                    }
                }
            }
            if (!isComment && line != "")
            {
                res.push_back(line);
                line = "";
            }
        }
        return res;
    }
};