#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <map>

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, map<int, int>> groups;
        for (int num : nums) {
            groups[num % k][num]++;
        }

        int ans = 1;
        // groups[idx]间的数据互不干扰,即绝对差不为k
        for (auto& [idx, group] : groups) {
            int gSize = group.size();
            // f[i][0]表示不选num[i]的方案数(空集):1
            // f[i][1]表示选num[i]的方案数(非空集):2^(num[i].size())-1
            vector<vector<int>> f(gSize, vector<int>(2, 0));
            f[0][0] = 1, f[0][1] = (1 << group.begin()->second) - 1;
            int i = 1;
            for (auto it = next(group.begin()); it != group.end(); it++, i++) {
                f[i][0] = f[i - 1][0] + f[i - 1][1];
                if (it->first - prev(it)->first == k) { // map已经排好序,所以不需要绝对差
                    f[i][1] = f[i - 1][0] * ((1 << it->second) - 1);
                }
                else {
                    f[i][1] = (f[i - 1][0] + f[i - 1][1]) * ((1 << it->second) - 1);
                }
            }
            ans *= f[gSize - 1][0] + f[gSize - 1][1];
        }
        return ans - 1; // 去除空集
    }
};