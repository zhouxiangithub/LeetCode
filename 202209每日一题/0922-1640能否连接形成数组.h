#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> index;
        for (int i = 0; i < pieces.size(); i++)
        {
            index[pieces[i][0]] = i;
        }
        for (int i = 0; i < arr.size();)
        {
            auto it = index.find(arr[i]);
            if (it == index.end())
            {
                return false;
            }
            for (int value : pieces[it->second])
            {
                if (arr[i++] != value)
                {
                    return false;
                }
            }
        }
        return true;
    }
};