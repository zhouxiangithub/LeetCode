#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
private:
    const static int SIZE = 2;

    void help(vector<vector<int>>& intervals, vector<vector<int>>& temp, int pos, int num) {
        for (int i = pos; i >= 0; i--) {
            if (intervals[i][1] < num) {
                break; // 不用continue,以最近的为准(贪心)
            }
            temp[i].push_back(num);
        }
    }

public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
            });
        vector<vector<int>> tmp(n);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = intervals[i][0], k = tmp[i].size(); k < SIZE; j++, k++) {
                res++;
                help(intervals, tmp, i - 1, j);
            }
        }
        return res;
    }
};