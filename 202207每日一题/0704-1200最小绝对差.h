#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        int min = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            int diff = arr[i + 1] - arr[i];
            if (diff < min)
            {
                min = diff;
                ans = { {arr[i],arr[i + 1]} };
            }
            else if (diff == min)
            {
                ans.emplace_back(initializer_list<int>{arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};