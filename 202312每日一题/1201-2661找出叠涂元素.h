#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[mat[i][j]] = { i,j };
            }
        }
        vector<int> rowCnt(m, 0);
        vector<int> colCnt(n, 0);
        for (int i = 0; i < arr.size(); i++)
        {
            auto& v = mp[arr[i]];
            rowCnt[v.first]++;
            if (rowCnt[v.first] == n)
            {
                return i;
            }
            colCnt[v.second]++;
            if (colCnt[v.second] == m)
            {
                return i;
            }
        }
        return -1;
    }
};