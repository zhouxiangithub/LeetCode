#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> f(2 * n + 1, INT_MAX / 2); //f(i,j)表示前i位油漆匠免费工作的次数为j时的最少开销
        f[n] = 0; //n+1 ~ 2n
        for (int i = 0; i < n; i++) {
            vector<int> g(2 * n + 1, INT_MAX / 2);
            for (int j = 0; j <= 2 * n; j++) {
                //付费 f(i+1,j+time[i]) <== f(i,j)+cost[i]
                g[min(j + time[i], 2 * n)] = min(g[min(j + time[i], 2 * n)], f[j] + cost[i]);
                //免费 f(i+1,j-1) <== f(i,j)
                if (j > 0) {
                    g[j - 1] = min(g[j - 1], f[j]);
                }
            }
            f = move(g);
        }
        return *min_element(f.begin() + n, f.end());
    }
};