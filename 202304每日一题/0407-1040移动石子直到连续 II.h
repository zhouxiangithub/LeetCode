#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();

        //��ʯ�������,��ʯ�Ӽ�Ŀ�λ��Ϊ0,��ʯ���Ѿ�����
        sort(stones.begin(), stones.end());
        if (stones.back() - stones[0] + 1 == n) 
        {
            return { 0,0 };
        }

        //��������
        int ma = max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
        
        //��С������:ʯ�����ն��ƶ�������Ϊn�Ĵ�����
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