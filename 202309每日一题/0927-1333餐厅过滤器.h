#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n = restaurants.size();
        vector<vector<int>> filter;
        for (int i = 0; i < n; i++)
        {
            if (restaurants[i][2] >= veganFriendly && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance)
            {
                filter.push_back(restaurants[i]);
            }
        }
        sort(filter.begin(), filter.end(), [](vector<int>& v1, vector<int>& v2)->bool
            {
                return v1[1] == v2[1] ? (v1[0] > v2[0]) : (v1[1] > v2[1]);
            });
        vector<int> res;
        for (auto& v : filter)
        {
            res.push_back(v[0]);
        }
        return res;
    }
};