#pragma once
using namespace std;
#include <vector>
#include <set>
#include <unordered_map>

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n);
        set<int> idxSet;
        unordered_map<int, int> valToIdxMap;
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                idxSet.insert(i);
            }
            else {
                res[i] = -1;
                if (valToIdxMap.count(rains[i])) {
                    auto it = idxSet.lower_bound(valToIdxMap[rains[i]]);
                    if (it == idxSet.end()) {
                        return {};
                    }
                    res[*it] = rains[i];
                    idxSet.erase(it);
                }
                valToIdxMap[rains[i]] = i;
            }
        }
        return res;
    }
};