#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), [&](const string& a, const string& b) {
            return a.size() < b.size();
            });
        unordered_set<string> dic;
        vector<string> ans;
        for (int i = 0; i < folder.size(); i++)
        {
            string tmp = "";
            for (int j = 0; j < folder[i].size(); j++)
            {
                if (folder[i][j] == '/' && tmp != "")
                {
                    if (dic.find(tmp) != dic.end())
                    {
                        break;
                    }
                }
                tmp += folder[i][j];
                if (j == folder[i].size() - 1)
                {
                    ans.emplace_back(folder[i]);
                    dic.insert(folder[i]);
                }
            }
        }
        return ans;
    }
};