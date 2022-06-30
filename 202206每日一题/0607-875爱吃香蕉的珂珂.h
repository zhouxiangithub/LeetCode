#pragma once
using namespace std;
#include <vector>

//¶þ·Ö·¨
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (int pile : piles)
        {
            high = max(pile, high);
        }
        int k = high;
        while (low < high)
        {
            int speed = (high - low) / 2 + low;
            long time = getTime(piles, speed);
            if (time <= h)
            {
                k = speed;
                high = speed;
            }
            else
            {
                low = speed + 1;
            }
        }
        return k;
    }

    long getTime(const vector<int>& piles, int speed)
    {
        long time = 0;
        for (int pile : piles)
        {
            int curTime = (pile % speed) ? (pile / speed + 1) : (pile / speed);
            time += curTime;
        }
        return time;
    }
};