#pragma once
using namespace std;
#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());
        int res = 0;
        double sum = accumulate(nums.begin(), nums.end(), 0.0), decreaseSum = 0.0;
        while (decreaseSum < sum / 2)
        {
            double num = pq.top();
            pq.pop();
            decreaseSum += num / 2;
            pq.push(num / 2);
            res++;
        }
        return res;
    }
};