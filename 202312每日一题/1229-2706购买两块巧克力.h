#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mi = INT_MAX, se = INT_MAX;
        for (auto price : prices)
        {
            if (price < mi)
            {
                se = mi;
                mi = price;
            }
            else if (price < se)
            {
                se = price;
            }
        }
        return money < mi + se ? money : (money - mi - se);
    }
};