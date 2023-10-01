#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < m; i++)
        {
            if (flowerbed[i] == 1)
            {
                if (prev < 0)
                {
                    count += i / 2;
                }
                else
                {
                    count += (i - prev - 2) / 2; // (i-1)-(prev+1)+1=i-prev-1
                }
                if (count >= n)
                {
                    return true;
                }
                prev = i;
            }
        }
        if (prev < 0)
        {
            count += (m + 1) / 2;
        }
        else
        {
            count += (m - prev - 1) / 2; //(m-1)-(prev+1)+1=(m-prev-1)
        }
        return count >= n;
    }
};