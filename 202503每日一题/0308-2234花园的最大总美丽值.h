#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        for (int& flower : flowers) {
            flower = min(flower, target);
        }
        sort(flowers.begin(), flowers.end(), greater<int>());
        long long sum = accumulate(flowers.begin(), flowers.end(), 0LL);
        long long ans = 0;
        // 若 > 则存在 不完善, 另外 全完善 并不一定是最大值
        if (static_cast<long long>(target) * n - sum <= newFlowers) {
            ans = static_cast<long long>(full) * n;
        }

        long long pre = 0;
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                pre += flowers[i - 1];
            }
            if (flowers[i] == target) {
                continue;
            }
            long long rest = newFlowers - (static_cast<long long>(target) * i - pre);
            if (rest < 0) {
                break;
            }
            // flowers已经从大到小排序, 尝试 不完善 尽可能的大
            while (!(ptr >= i && static_cast<long long>(flowers[ptr]) * (n - ptr) - sum <= rest)) {
                sum -= flowers[ptr];
                ptr++;
            }
            rest -= static_cast<long long>(flowers[ptr]) * (n - ptr) - sum;
            ans = max(ans, static_cast<long long>(full) * i + static_cast<long long>(partial) * (min(flowers[ptr] + rest / (n - ptr), static_cast<long long>(target) - 1)));
        }
        return ans;
    }
};