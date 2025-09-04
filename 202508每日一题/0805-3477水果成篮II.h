#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = 0;
        for (auto fruit : fruits) {
            int cnt = 1;
            for (int i = 0; i < baskets.size(); i++) {
                if (baskets[i] >= fruit) {
                    baskets[i] = 0;
                    cnt = 0;
                    break;
                }
            }
            res += cnt;
        }
        return res;
    }
};