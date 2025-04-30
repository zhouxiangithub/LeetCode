#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <cmath>

// ���� x �� y �������� ceil[x/(y+1)] = (x+y)/(y+1) ������
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int answer : answers) {
            count[answer]++;
        }
        int ans = 0;
        for (auto& [y, x] : count) {
            ans += (x + y) / (y + 1) * (y + 1);
        }
        return ans;
    }
};