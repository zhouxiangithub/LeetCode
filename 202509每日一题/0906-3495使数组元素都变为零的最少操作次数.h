#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
    using ll = long long;
public:
    ll getCnt(vector<int> query) {
        int cnt = 0;
        priority_queue<int> q;
        for (int i = query[0]; i <= query[1]; i++) {
            q.emplace(i);
        }
        while (q.top()) {
            cnt++;
            int maxNum = q.top();
            q.pop();
            int secondMaxNum = q.top();
            q.pop();
            q.push(maxNum / 4);
            q.push(secondMaxNum / 4);
        }
        return cnt;
    }

    long long minOperations(vector<vector<int>>& queries) {
        ll res = 0;
        for (auto& query : queries) {
            res += getCnt(query);
        }
        return res;
    }
};

// 对于长度为 x 的二进制，需操作 (x+1)/2 次
class Solution {
    using ll = long long;
public:
    ll f(int num) {
        int i = 1;
        int base = 1;
        ll cnt = 0;
        while (base <= num) {
            cnt += 1ll * (i + 1) / 2 * (min(base * 2 - 1, num) - base + 1); // [base, 2*base-1]
            i++;
            base *= 2;
        }
        return cnt;
    }

    long long minOperations(vector<vector<int>>& queries) {
        ll res = 0;
        for (auto& query : queries) {
            res += ((f(query[1]) - f(query[0] - 1)) + 1) / 2; // 向上取整
        }
        return res;
    }
};