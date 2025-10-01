#pragma once
using namespace std;
#include <queue>

/*
    A 1 ==> 1+delay,...,1+forget-1 ==> [3,4] +2
    B 3 ==> 3+delay,...,3+forget-1 ==> [5,6] +2
    C 4 ==> 4+delay,...,4+forget-1 ==> [6,7] +1
    D 5 ==> 5+delay,...,5+forget-1 ==> [7,8]

    A 1 ==> 1+delay,...,1+forget-1 ==> [2,3] +2
    B 2 ==> 2+delay,...,2+forget-1 ==> [3,4] +2
    C 3 ==> 3+delay,...,3+forget-1 ==> [4,5] +1
    D 3 ==> 3+delay,...,3+forget-1 ==> [4,5] +1

    x+forget > n   +1
    x <= n         push
*/
class Solution {
private:
    const static int MOD = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int res = 0;
        queue<int> que;
        que.push(1);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            if (x + forget > n) {
                res %= MOD;
                res++;
            }
            for (int y = x + delay; y <= min(n, x + forget - 1); y++) {
                que.push(y);
            }
        }
        return res;
    }
};

class Solution {
private:
    const static int MOD = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<pair<int, int>> know, share;
        know.emplace_back(1, 1);
        int knowCnt = 1, shareCnt = 0;
        for (int i = 2; i <= n; i++) {
            if (!know.empty() && know[0].first + delay == i) {
                knowCnt = (knowCnt - know[0].second + MOD) % MOD;
                shareCnt = (shareCnt + know[0].second) % MOD;
                share.push_back(know[0]);
                know.pop_front();
            }
            if (!share.empty() && share[0].first + forget == i) {
                shareCnt = (shareCnt - share[0].second + MOD) % MOD;
                share.pop_front();
            }
            if (!share.empty()) {
                knowCnt = (knowCnt + shareCnt) % MOD;
                know.emplace_back(i, shareCnt);
            }
        }
        return (knowCnt + shareCnt) % MOD;
    }
};