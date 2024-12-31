#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        vector<int> occ;
        for (auto& [k, v] : freq) {
            occ.push_back(v);
        }
        sort(occ.begin(), occ.end(), greater<int>());
        int count = 0, res = 0;
        for (int cnt : occ) {
            count += cnt;
            res++;
            if (count * 2 >= arr.size()) {
                break;
            }
        }
        return res;
    }
};