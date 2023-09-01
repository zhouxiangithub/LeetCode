#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int res = 0;
        int left = 0;
        while (left < n && seats[left] == 0)
        {
            left++;
        }
        res = max(res, left);
        while (left < n)
        {
            int right = left + 1;
            while (right < n && seats[right] == 0)
            {
                right++;
            }
            if (right == n)
            {
                res = max(res, right - left - 1);
            }
            else
            {
                res = max(res, (right - left) / 2);
            }
            left = right;
        }
        return res;
    }
};