#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        unordered_map<int, int> mp;
        for (int num : nums1) {
            mp[num]++;
        }

        vector<int> res;
        for (int num : nums2) {
            if (mp.count(num)) {
                res.push_back(num);
                mp[num]--;
                if (mp[num] == 0) {
                    mp.erase(num);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int s1 = nums1.size(), s2 = nums2.size();
        vector<int> res;
        int idx1 = 0, idx2 = 0;
        while (idx1 < s1 && idx2 < s2) {
            if (nums1[idx1] < nums2[idx2]) {
                idx1++;
            }
            else if (nums1[idx1] > nums2[idx2]) {
                idx2++;
            }
            else {
                res.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            }
        }
        return res;
    }
};