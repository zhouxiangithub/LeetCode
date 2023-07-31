#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum % 2)
        {
            return res;
        }
        for (int i = 2; i <= finalSum; i += 2)
        {
            res.push_back(i);
            finalSum -= i;
        }
        res.back() += finalSum;
        return res;
    }
};