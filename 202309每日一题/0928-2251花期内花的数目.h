#pragma once
using namespace std;
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> cnt;
        for (auto& flower : flowers)
        {
            cnt[flower[0]]++;
            cnt[flower[1] + 1]--;
        }
        int n = persons.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return persons[a] < persons[b];
            });

        vector<int> ans(n);
        int cur = 0;
        auto it = cnt.begin();
        for (int x : idx)
        {
            while (it != cnt.end() && it->first <= persons[x])
            {
                cur += it->second;
                it++;
            }
            ans[x] = cur;
        }
        return ans;
    }
};