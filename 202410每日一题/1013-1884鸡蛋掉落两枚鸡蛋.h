#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> f(n + 1, n + 1); // f[i] ��ʾ i ��¥�Ľ�����Ҫ����С��������
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                f[i] = min(f[i], max(k - 1, f[i - k]) + 1);
            }
        }
        return f[n];
    }
};