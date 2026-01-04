#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
private:
    const static int MOD = 1e9 + 7;

public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> pointNum;
        for (auto& point : points) {
            pointNum[point[1]]++; // 将平行于 x 轴的边聚集:纵坐标相同的点属同类别
        }
        long long res = 0, sum = 0;
        for (auto& [_, pNum] : pointNum) {
            long long edge = (long long)pNum * (pNum - 1) / 2;
            res += edge * sum;
            sum += edge;
        }
        return res % MOD;
    }
};