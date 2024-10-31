#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> numCnt1, numCnt2;
        int max1 = 0;
        for (int num1 : nums1) {
            numCnt1[num1]++;
            max1 = max(max1, num1);
        }
        for (int num2 : nums2) {
            numCnt2[num2]++;
        }
        long long res = 0;
        for (const auto& pair : numCnt2) {
            int num = pair.first, cnt = pair.second;
            for (int num2 = num * k; num2 <= max1; num2 += num * k) {
                if (numCnt1.count(num2)) {
                    res += 1L * numCnt1[num2] * cnt;
                }
            }
        }
        return res;
    }
};