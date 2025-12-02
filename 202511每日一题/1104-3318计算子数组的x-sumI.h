#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i <= n - k; i++) {
            vector<int> subArr(nums.begin() + i, nums.begin() + i + k);
            unordered_map<int, int> valToCnt;
            for (int num : subArr) {
                valToCnt[num]++;
            }

            vector<pair<int, int>> cntToVal;
            for (auto& p : valToCnt) {
                cntToVal.emplace_back(-p.second, -p.first);
            }
            sort(cntToVal.begin(), cntToVal.end());

            unordered_map<int, bool> isSelected;
            int selectNum = min(x, (int)cntToVal.size()); // 频率出现最高的前 x 种元素
            for (int j = 0; j < selectNum; j++) {
                int val = -cntToVal[j].second;
                isSelected[val] = true;
            }

            int sum = 0;
            for (int num : subArr) {
                if (isSelected.count(num)) {
                    sum += num;
                }
            }
            res.push_back(sum);
        }
        return res;
    }
};