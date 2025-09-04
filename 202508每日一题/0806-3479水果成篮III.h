#pragma once
using namespace std;
#include <vector>

// 分块
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int m = sqrt(n); // 块大小
        int num = (n + m - 1) / m; // 块数量
        int res = 0;
        vector<int> maxV(num); // 存储每个块的最大容量
        for (int i = 0; i < n; i++) {
            maxV[i / m] = max(maxV[i / m], baskets[i]);
        }
        for (int fruit : fruits) {
            int unplaced = 1;
            for (int v = 0; v < num; v++) {
                if (fruit > maxV[v]) {
                    continue;
                }
                // 块v中存在
                maxV[v] = 0;
                int choose = 0;
                for (int i = 0; i < m; i++) {
                    int pos = v * m + i;
                    if (pos < n) {
                        if (!choose && baskets[pos] >= fruit) {
                            choose = 1;
                            baskets[pos] = 0;
                        }
                        // 重新调整该块的最大值
                        maxV[v] = max(maxV[v], baskets[pos]);
                    }
                }
                unplaced = 0;
                break;
            }
            res += unplaced;
        }
        return res;
    }
};