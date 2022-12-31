#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;
        for (auto& i : nums1)
        {
            mp[i] = 1; //001
        }
        for (auto& i : nums2)
        {
            mp[i] |= 2; //010
        }
        for (auto& i : nums3)
        {
            mp[i] |= 4; //100
        }
        vector<int> res;
        for (auto& [k, v] : mp)
        {
            //111 011 101 110 (ok)
            //000 100 010 001 (not ok)
            if (v & (v - 1))
            {
                res.push_back(k);
            }
        }
        return res;
    }
};