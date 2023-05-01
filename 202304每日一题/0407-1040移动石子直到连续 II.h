#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();

        //当石子排序后,若石子间的空位数为0,则石子已经连续
        sort(stones.begin(), stones.end());
        if (stones.back() - stones[0] + 1 == n) 
        {
            return { 0,0 };
        }

        //最大操作数
        int ma = max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
        
        //最小操作数:石子最终都移动到长度为n的窗口中
        int mi = n;
        for (int i = 0, j = 0; i < n && j + 1 < n; i++)
        {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n)
            {
                j++;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1)
            {
                mi = min(mi, 2);
            }
            else
            {
                mi = min(mi, n - (j - i + 1));
            }
        }
        return { mi,ma };
    }
};