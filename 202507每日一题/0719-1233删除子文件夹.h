#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res = { folder[0] };
        for (int i = 1; i < folder.size(); i++) {
            int pre = (*(res.end() - 1)).size();
            if (!(folder[i].size() > pre && folder[i].substr(0, pre) == *(res.end() - 1) && folder[i][pre] == '/')) {
                res.push_back(folder[i]);
            }
        }
        return res;
    }
};