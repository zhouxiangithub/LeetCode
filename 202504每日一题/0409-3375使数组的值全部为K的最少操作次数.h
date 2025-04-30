#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int num : nums) {
            if (num < k) {
                return -1;
            }
            else if (num > k) {
                st.insert(num);
            }
        }
        return st.size();
    }
};