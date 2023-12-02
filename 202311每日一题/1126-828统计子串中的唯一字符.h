#pragma once
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> ch_idx;
        for (int i = 0; i < s.size(); i++)
        {
            ch_idx[s[i]].emplace_back(i);
        }
        int res = 0;
        for (auto&& [_, arr] : ch_idx)
        {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(s.size());
            for (int i = 1; i < arr.size() - 1; i++)
            {
                res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return res;
    }
};