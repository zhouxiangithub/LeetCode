#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
    //哈希表
    unordered_map<int, vector<int>> pos; //值--索引列表
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            pos[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto& indices = pos[target];
        return indices[rand() % indices.size()];
    }
};

class Solution {
    //水塘抽样
    vector<int>& nums;
public:
    Solution(vector<int>& nums) : nums(nums) {}

    int pick(int target) {
        int ans;
        for (int i = 0, cnt = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                cnt++; //第cnt次遇到target
                if (rand() % cnt == 0)
                {
                    ans = i;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */