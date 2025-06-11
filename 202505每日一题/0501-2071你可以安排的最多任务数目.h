#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int num)->bool {
            int p = pills;
            multiset<int> mSet;
            // 存储工人集合最大的 num 个
            for (int i = m - num; i < m; i++) {
                mSet.insert(workers[i]);
            }
            // 从大到小枚举任务
            for (int i = num - 1; i >= 0; i--) {
                if (auto it = prev(mSet.end()); *it >= tasks[i]) {
                    mSet.erase(it);
                }
                else {
                    if (!p) { // 工人最大都没任务大且神奇药丸也没了
                        return false;
                    }
                    auto iter = mSet.lower_bound(tasks[i] - strength);
                    if (iter == mSet.end()) {
                        return false;
                    }
                    p--;
                    mSet.erase(iter);
                }
            }
            return true;
        };

        int left = 1, right = min(n, m), res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};