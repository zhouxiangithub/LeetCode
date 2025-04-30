#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll res = 0;
        int border = -1, lastMin = -1, lastMax = -1; // borderΪ��߽�(������),��border+1Ϊ�����ڵ�һ������
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]<minK || nums[i]>maxK) {
                lastMin = -1;
                lastMax = -1;
                border = i;     
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            if (lastMin != -1 && lastMax != -1) {
                res += min(lastMin, lastMax) - border; // -(border+1)+1
            }
        }
        return res;
    }
};