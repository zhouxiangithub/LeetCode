#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int res = 0;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] >= target) {
                res++;
            }
        }
        return res;
    }
};