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
        
        //余数为[1,29]的歌曲i与(60-i)配对
        for (int i = 1; i < 30; i++)
        {
            res += cnt[i] * cnt[60 - i];
        }

        //余数为0和余数为30的歌曲
        res += (long long)cnt[0] * (cnt[0] - 1) / 2 + (long long)cnt[30] * (cnt[30] - 1) / 2;
        
        return (int)res;
    }
};