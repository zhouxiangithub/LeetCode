#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    int res;
    int n;
public:
    void dfs(int val, int idx, vector<int>& nums) {
        if (idx == n) {
            res += val;
            return;
        }
        dfs(val ^ nums[idx], idx + 1, nums); // 选择当前数字
        dfs(val, idx + 1, nums); // 不选择当前数字
    }

    int subsetXORSum(vector<int>& nums) {
        res = 0;
        n = nums.size();
        dfs(0, 0, nums);
        return res;
    }
};