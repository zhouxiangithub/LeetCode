#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> distance;
        int res = 0, dis = 0;
        for (int i = 0; i < garbage.size(); i++) {
            res += garbage[i].size();
            if (i > 0) {
                dis += travel[i - 1];
            }
            for (auto c : garbage[i]) {
                distance[c] = dis;
            }
        }
        for (auto& [key, value] : distance) {
            res += value;
        }
        return res;
    }
};