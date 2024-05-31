#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int prev = max(arr[0], arr[1]);
        if (k == 1) {
            return prev;
        }
        int cons = 1;
        int ma = prev;
        int n = arr.size();
        for (int i = 2; i < n; i++) {
            int cur = arr[i];
            if (prev > cur) {
                cons++;
                if (cons == k) {
                    return prev;
                }
            }
            else {
                prev = cur;
                cons = 1;
            }
            ma = max(ma, cur);
        }
        return ma;
    }
};