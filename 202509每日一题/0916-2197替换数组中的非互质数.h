#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            while (!res.empty()) {
                int g = gcd(res.back(), num);
                if (g > 1) {
                    num = res.back() / g * num;
                    res.pop_back();
                }
                else {
                    break;
                }
            }
            res.push_back(num);
        }
        return res;
    }
};