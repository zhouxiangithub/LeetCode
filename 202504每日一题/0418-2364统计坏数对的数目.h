#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    using ll = long long;
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> uMap;
        ll res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += i - uMap[nums[i] - i]; // 去掉此前相等的就是不等的对
            uMap[nums[i] - i]++;
        }
        return res;
    }
};