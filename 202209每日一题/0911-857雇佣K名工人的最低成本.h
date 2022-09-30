#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>

/*
    假设组成成员为：[h1,h2,...,hk]，整个工作组的总工作质量为totalq，总的支付金额为totalc，那么：
        totalc * (quality[hi] / totalq) >= wage[hi]
    即：
        totalc >= totalq * (wage[hi] / quality[hi])
*/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> h(n, 0);
        iota(h.begin(), h.end(), 0); // 0 ~ n-1
        sort(h.begin(), h.end(), [&](int& a, int& b) {
            return quality[a] * wage[b] > quality[b] * wage[a];
            }); //将工人按照权重进行升序排序
        double res = 1e9;
        double totalq = 0.0;
        priority_queue<int, vector<int>, less<int>> q; //从小到大排列(默认)，q.top()返回最大值
        //取(k-1)个最小的
        for (int i = 0; i < k - 1; i++)
        {
            totalq += quality[h[i]];
            q.push(quality[h[i]]);
        }
        //每一个能成为最大权重的最小工资开销
        for (int i = k - 1; i < n; i++)
        {
            int idx = h[i];
            totalq += quality[idx];
            q.push(quality[idx]);
            double totalc = ((double)wage[idx] / quality[idx]) * totalq;
            res = min(res, totalc);
            totalq -= q.top();
            q.pop();
        }
        return res;
    }
};