#pragma once
using namespace std;
#include <vector>
#include <random>

class Solution {
public:
    /*
        rects[i]=[ai,bi,xi,yi]
        整数点一共有 yi-bi+1 行，xi-ai+1 列
        在同一个矩形中的编号，左下角点(ai, bi)编号为：0，
        在同一行中，随着横坐标的增加，编号增加
        右下角点(xi, bi)在这个矩形中的编号为：xi-ai
    */
    Solution(vector<vector<int>>& rects) :rects{ rects } {
        this->arr.emplace_back(0);
        for (auto& rect : rects)
        {
            this->arr.emplace_back(arr.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        }
    }

    vector<int> pick() {
        uniform_int_distribution<int> dis(0, arr.back() - 1);
        int k = dis(gen) % arr.back();
        int rectIndex = upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;
        k = k - arr[rectIndex];
        int a = rects[rectIndex][0], b = rects[rectIndex][1];
        int y = rects[rectIndex][3];
        int col = y - b + 1;
        int da = k / col;
        int db = k % col;
        return { a + da,b + db };
    }
private:
    vector<int> arr;
    vector<vector<int>>& rects;
    mt19937 gen{ random_device{}() };
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */