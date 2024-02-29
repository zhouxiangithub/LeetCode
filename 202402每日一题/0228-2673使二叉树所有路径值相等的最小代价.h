#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        //将互为兄弟节点的叶节点对齐后将较大值累加到其双亲节点上作为新一轮的叶节点
        for (int i = n - 2; i > 0; i -= 2)
        {
            ans += abs(cost[i] - cost[i + 1]);
            cost[i / 2] += max(cost[i], cost[i + 1]); //叶节点i和i+1的双亲节点为i/2
        }
        return ans;
    }
};