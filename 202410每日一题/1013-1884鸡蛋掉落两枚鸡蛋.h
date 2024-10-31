#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> f(n + 1, n + 1); // f[i] 表示 i 层楼的建筑需要的最小操作次数
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                f[i] = min(f[i], max(k - 1, f[i - k]) + 1);
            }
        }
        return f[n];
    }
};