#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // ����ӵ͵��ߵ� k ��������λ��ֵΪ 1 ��Ԫ�ظ���
        auto maxLen = [&](int k)->int {
            int res = 0;
            for (int num : candidates) {
                if (num & (1 << k)) {
                    res++;
                }
            }
            return res;
        };

        // 10^7 < 2^24 < 10^8
        int ans = 0;
        for (int i = 0; i < 24; i++) {
            ans = max(ans, maxLen(i));
        }
        return ans;
    }
};