#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n);
        if (k == 0) {
            return res;
        }
        code.resize(2 * n);
        copy(code.begin(), code.begin() + n, code.begin() + n);
        int left = k > 0 ? 1 : n + k;
        int right = k > 0 ? k : n - 1;
        int win = 0;
        for (int i = left; i <= right; i++) {
            win += code[i];
        }
        for (int i = 0; i < n; i++) {
            res[i] = win;
            win -= code[left];
            win += code[right + 1];
            left++;
            right++;
        }
        return res;
    }
};