#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        vector<int> points;
        for (auto& op : ops) {
            int n = points.size();
            switch (op[0]) {
            case '+':
                res += points[n - 1] + points[n - 2];
                points.push_back(points[n - 1] + points[n - 2]);
                break;
            case 'D':
                res += 2 * points[n - 1];
                points.push_back(2 * points[n - 1]);
                break;
            case 'C':
                res -= points[n - 1];
                points.pop_back();
                break;
            default:
                res += stoi(op);
                points.push_back(stoi(op));
                break;
            }
        }
        return res;
    }
};