#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0, left = 0;
        unordered_map<int, int> cnt;
        for (int right = 0; right < fruits.size(); right++) {
            cnt[fruits[right]]++;
            while (cnt.size() > 2) {
                auto it = cnt.find(fruits[left]);
                it->second--;
                if (it->second == 0) {
                    cnt.erase(it);
                }
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};