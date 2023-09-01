#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0, n = nums.size();
        while (i < n)
        {
            int left = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1)
            {
                i++;
            }
            int right = i - 1;
            string str = to_string(nums[left]);
            if (left < right)
            {
                str.append("->");
                str.append(to_string(nums[right]));
            }
            ans.emplace_back(move(str));
        }
        return ans;
    }
};