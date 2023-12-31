#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool isBalance(int x)
    {
        vector<int> count(10);
        while (x)
        {
            count[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d < 10; d++)
        {
            if (count[d] && count[d] != d)
            {
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++)
        {
            if (isBalance(i))
            {
                return i;
            }
        }
        return -1;
    }
};