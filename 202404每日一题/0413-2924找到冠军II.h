#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        for (auto& edge : edges) {
            degree[edge[1]]++;
        }
        int champ = -1;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                if (champ == -1) {
                    champ = i;
                }
                else
                {
                    return -1;
                }
            }
        }
        return champ;
    }
};