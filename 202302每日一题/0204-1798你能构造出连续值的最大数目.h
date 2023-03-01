#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    �����Ѿ������[0,x],����y��ɹ����������Ϊ:[0,x]��[y,x+y]
*/
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int res = 1;
        sort(coins.begin(), coins.end());
        for (auto& i : coins)
        {
            if (i > res)
            {
                break;
            }
            res += i;
        }
        return res;
    }
};