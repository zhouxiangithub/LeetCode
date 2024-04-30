#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) {
            return {};
        }
        sort(changed.begin(), changed.end());
        unordered_map<int, int> count;
        for (int a : changed) {
            count[a]++;
        }
        vector<int> res;
        for (int a : changed) {
            if (count[a] == 0) {
                continue;
            }
            count[a]--;
            if (count[2 * a] == 0) {
                return {};
            }
            count[2 * a]--;
            res.push_back(a);
        }
        return res;
    }
};