#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int res = 0;
        for (int battery : batteryPercentages) {
            if (battery > res) {
                res++;
            }
        }
        return res;
    }
};