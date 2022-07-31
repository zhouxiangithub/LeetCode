#pragma once
using namespace std;
#include <vector>

/*
    遍历数组，从i向nums[i]连边，可以得到一张有向图。找到节点个数最大的环即可。
*/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> vis(n);
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            while (!vis[i])
            {
                vis[i] = true;
                i = nums[i];
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/*
    nums中的元素大小在[0,n-1]之间
*/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            while (nums[i] < n)
            {
                int num = nums[i];
                nums[i] = n;
                i = num;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};