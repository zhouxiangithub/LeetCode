#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    using ll = long long;
    long long repairCars(vector<int>& ranks, int cars) {
        ll left = 1, right = 1ll * ranks[0] * cars * cars;
        auto check = [&](ll m)
        {
            ll cnt = 0;
            for (auto rank : ranks)
            {
                cnt += sqrt(m / rank);
            }
            return cnt >= cars;
        };
        while (left < right)
        {
            ll mid = (left + right) >> 1;
            if (check(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};