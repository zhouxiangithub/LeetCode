#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
private:
    unordered_map<int, int> cnt;
public:
    int findLucky(vector<int>& arr) {
        for (auto num : arr) {
            cnt[num]++;
        }

        int res = -1;
        for (auto [key, value] : cnt) {
            if (key == value) {
                res = max(res, key);
            }
        }
        return res;
    }
};