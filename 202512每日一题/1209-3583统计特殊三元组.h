#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
private:
    const static int MOD = 1e9 + 7;

public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> totalCnt;
        unordered_map<int, int> leftCnt;

        for (int num : nums) {
            totalCnt[num]++;
        }

        int res = 0;
        for (int num : nums) {
            int target = num * 2;
            int lCnt = leftCnt[target];
            leftCnt[num]++;
            int rCnt = totalCnt[target] - leftCnt[target];
            res = (res + (lCnt * 1LL * rCnt % MOD)) % MOD;
        }
        return res;
    }
};