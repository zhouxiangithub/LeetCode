#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits_max_pos(31, -1);
        vector<pair<int, int>> pos_to_bit;
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 30; j++) {
                if (nums[i] >> j & 1) {
                    bits_max_pos[j] = i;
                }
            }
            pos_to_bit.clear();
            for (int j = 0; j <= 30; j++) {
                if (bits_max_pos[j] != -1) {
                    pos_to_bit.push_back(make_pair(bits_max_pos[j], j));
                }
            }
            sort(pos_to_bit.begin(), pos_to_bit.end(), greater<pair<int, int>>());
            int val = 0;
            for (int j = 0, p = 0; j < pos_to_bit.size();) {
                while (j < pos_to_bit.size() && pos_to_bit[j].first == pos_to_bit[p].first) {
                    val |= 1 << pos_to_bit[j].second;
                    j++;
                }
                res = min(res, abs(val - k));
                p = j;
            }
        }
        return res;
    }
};

// 滑动窗口
class Solution {
private:
    // 更新位统计
    void updateBitCount(vector<int>& bitCountRecord, int num, int del) {
        int pos = 0;
        while (num > 0) {
            if (num & 1) {
                bitCountRecord[pos] += del;
            }
            num >>= 1;
            pos++;
        }
    }

    // 根据 bitCountRecord 重新计算当前按位或的值
    int reComputeValue(const vector<int>& bitCountRecord) {
        int value = 0;
        for (int i = 0; i < 32; i++) {
            if (bitCountRecord[i] > 0) {
                value |= (1 << i);
            }
        }
        return value;
    }

public:
    int minimumDifference(vector<int>& nums, int k) {
        vector<int> bitCountRecord(32, 0); // 记录每个位上的数量
        int n = nums.size(), left = 0, right = 0;
        int ans = INT_MAX;
        int cur = 0;
        for (left = 0; left < n; left++) {
            while (right < n && cur < k) {
                cur |= nums[right];
                updateBitCount(bitCountRecord, nums[right], 1);
                right++;
                ans = min(ans, abs(cur - k));
            }

            if (cur == k) {
                return 0;
            }

            // 移动左边界, 减去 nums[left] 对应的位统计, 并更新 cur
            updateBitCount(bitCountRecord, nums[left], -1);
            cur = reComputeValue(bitCountRecord);

            if (cur > 0) {
                ans = min(ans, abs(cur - k));
            }
        }
        return ans;
    }
};