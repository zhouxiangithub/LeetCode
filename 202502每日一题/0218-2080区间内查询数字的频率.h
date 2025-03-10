#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> occ;

public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            occ[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        const vector<int>& pos = occ[value];
        auto l = lower_bound(pos.begin(), pos.end(), left);
        auto r = upper_bound(pos.begin(), pos.end(), right);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */