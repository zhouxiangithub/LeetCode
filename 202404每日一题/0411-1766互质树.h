#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
private:
    vector<vector<int>> gcds; // gcds[i]表示[1,50]中与值i互质的值集合
    vector<vector<int>> tmp; // tmp[i]表示值为i的节点集合
    vector<vector<int>> g; // 路径
    vector<int> dep; // 深度
    vector<int> ans;

public:
    void dfs(vector<int>& nums, int x, int depth) {
        dep[x] = depth;
        for (int val : gcds[nums[x]]) { // 遍历与节点x的值nums[x]互质的值集合
            if (tmp[val].empty()) {
                continue;
            }

            int las = tmp[val].back(); // 集合末尾的节点与节点x最近
            if (ans[x] == -1 || dep[las] > dep[ans[x]]) {
                ans[x] = las;
            }
        }

        tmp[nums[x]].push_back(x);
        for (int val : g[x]) {
            if (dep[val] == -1) {
                dfs(nums, val, depth + 1);
            }
        }
        tmp[nums[x]].pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        // 初始化
        gcds.resize(51);
        tmp.resize(51);
        g.resize(n);
        dep.resize(n, -1);
        ans.resize(n, -1);

        // 预处理
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                if (gcd(i, j) == 1) {
                    gcds[i].push_back(j);
                }
            }
        }
        for (const auto& val : edges) {
            g[val[0]].push_back(val[1]);
            g[val[1]].push_back(val[0]);
        }

        dfs(nums, 0, 1);

        return ans;
    }
};