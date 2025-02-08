#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mp.count(num) && i - mp[num] <= k) {
                return true;
            }
            mp[num] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        // »¬¶¯´°¿Ú
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                st.erase(nums[i - k - 1]);
            }
            if (st.count(nums[i])) {
                return true;
            }
            st.emplace(nums[i]);
        }
        return false;
    }
};