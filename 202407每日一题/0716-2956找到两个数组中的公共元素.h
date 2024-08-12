#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> res(2);
        for (int num : nums1) {
            if (s2.count(num)) {
                res[0]++;
            }
        }
        for (int num : nums2) {
            if (s1.count(num)) {
                res[1]++;
            }
        }
        return res;
    }
};