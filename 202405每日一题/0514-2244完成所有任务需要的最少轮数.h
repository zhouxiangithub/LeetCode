#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (int task : tasks) {
            cnt[task]++;
        }
        int res = 0;
        for (auto [_, value] : cnt) {
            if (value == 1) {
                return -1;
            }
            else if (value % 3 == 0) {
                res += value / 3;
            }
            else
            {
                // 3k+1            ==> k+1
                // 3k+2=3(k-1)+3+2 ==> k-1+2=k+1
                res += value / 3 + 1;
            }
        }
        return res;
    }
};