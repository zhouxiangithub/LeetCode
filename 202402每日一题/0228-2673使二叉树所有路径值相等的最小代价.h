#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        //����Ϊ�ֵܽڵ��Ҷ�ڵ����󽫽ϴ�ֵ�ۼӵ���˫�׽ڵ�����Ϊ��һ�ֵ�Ҷ�ڵ�
        for (int i = n - 2; i > 0; i -= 2)
        {
            ans += abs(cost[i] - cost[i + 1]);
            cost[i / 2] += max(cost[i], cost[i + 1]); //Ҷ�ڵ�i��i+1��˫�׽ڵ�Ϊi/2
        }
        return ans;
    }
};