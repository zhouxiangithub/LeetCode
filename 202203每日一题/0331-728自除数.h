#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool isSelfDividing(int num)
    {
        int temp = num;
        while (temp)
        {
            int digit = temp % 10;
            if (digit == 0 || num % digit != 0)
            {
                return false;
            }
            temp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            if (isSelfDividing(i))
            {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};