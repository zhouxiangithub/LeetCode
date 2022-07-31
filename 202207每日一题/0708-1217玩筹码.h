#pragma once
using namespace std;
#include <vector>

//移到同一位置是指值相同
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int pos : position)
        {
            if (pos % 2) //奇数
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        return min(odd, even);
    }
};