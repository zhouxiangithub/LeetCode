#pragma once
using namespace std;

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (cost1 < cost2)
        {
            return waysToBuyPensPencils(total, cost2, cost1);
        }
        long res = 0, count1 = 0;
        while (count1 * cost1 <= total)
        {
            res += (total - count1 * cost1) / cost2 + 1;
            count1++;
        }
        return res;
    }
};