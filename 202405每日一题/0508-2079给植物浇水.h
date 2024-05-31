#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int ans = 0;
        int rest = capacity;
        for (int i = 0; i < n; i++) {
            if (rest >= plants[i]) {
                ans++;
                rest -= plants[i];
            }
            else
            {
                ans += 2 * i + 1;
                rest = capacity - plants[i];
            }
        }
        return ans;
    }
};