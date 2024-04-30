#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
private:
    vector<vector<int>> gcds; // gcds[i]��ʾ[1,50]����ֵi���ʵ�ֵ����
    vector<vector<int>> tmp; // tmp[i]��ʾֵΪi�Ľڵ㼯��
    vector<vector<int>> g; // ·��
    vector<int> dep; // ���
    vector<int> ans;

public:
    void dfs(vector<int>& nums, int x, int depth) {
        dep[x] = depth;
        for (int val : gcds[nums[x]]) { // ������ڵ�x��ֵnums[x]���ʵ�ֵ����
            if (tmp[val].empty()) {
                continue;
            }

            int las = tmp[val].back(); // ����ĩβ�Ľڵ���ڵ�x���
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

        // ��ʼ��
        gcds.resize(51);
        tmp.resize(51);
        g.resize(n);
        dep.resize(n, -1);
        ans.resize(n, -1);

        // Ԥ����
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