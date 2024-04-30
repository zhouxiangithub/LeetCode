#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                total += customers[i];
            }
        }
        int increase = 0;
        for (int i = 0; i < minutes; i++) {
            increase += customers[i] * grumpy[i];
        }
        int maxIncrease = increase;
        for (int i = minutes; i < n; i++) {
            increase = increase + customers[i] * grumpy[i] - customers[i - minutes] * grumpy[i - minutes];
            maxIncrease = max(maxIncrease, increase);
        }
        return total + maxIncrease;
    }
};