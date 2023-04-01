#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> f(n + 1); //f[i]��ʾǰi��Ԫ��֮��:nums[0]+nums[1]+...+nums[i-1]
        for (int i = 0; i < n; i++)
        {
            f[i + 1] = f[i] + nums[i];
        }
        vector<int> answer(m);
        for (int i = 0; i < m; i++)
        {
            answer[i] = upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1;
        }
        return answer;
    }
};