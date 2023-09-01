#pragma once
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, vector<int>> sidx_ind;
        for (int i = 0; i < indices.size(); i++)
        {
            sidx_ind[indices[i]].push_back(i);
        }
        string ans;
        for (int i = 0; i < s.size();)
        {
            bool succeed = false;
            if (sidx_ind.count(i))
            {
                for (int ind : sidx_ind[i])
                {
                    if (s.substr(i, sources[ind].size()) == sources[ind])
                    {
                        succeed = true;
                        ans += targets[ind];
                        i += sources[ind].size();
                        break;
                    }
                }
            }
            if (!succeed)
            {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};