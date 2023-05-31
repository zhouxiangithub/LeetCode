#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for (int t : time)
        {
            cnt[t % 60]++;
        }
        long long res = 0;
        
        //����Ϊ[1,29]�ĸ���i��(60-i)���
        for (int i = 1; i < 30; i++)
        {
            res += cnt[i] * cnt[60 - i];
        }

        //����Ϊ0������Ϊ30�ĸ���
        res += (long long)cnt[0] * (cnt[0] - 1) / 2 + (long long)cnt[30] * (cnt[30] - 1) / 2;
        
        return (int)res;
    }
};