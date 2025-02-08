#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    const static int MOD = 1e9 + 7;
    
    int countTexts(string pressedKeys) {
        vector<long long> dp3 = { 1,1,2,4 };
        vector<long long> dp4 = { 1,1,2,4 };
        int n = pressedKeys.size();
        for (int i = 4; i < n + 1; i++) {
            dp3.push_back((dp3[i - 1] + dp3[i - 2] + dp3[i - 3]) % MOD);
            dp4.push_back((dp4[i - 1] + dp4[i - 2] + dp4[i - 3] + dp4[i - 4]) % MOD);
        }
        long long res = 1;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (pressedKeys[i] == pressedKeys[i - 1]) {
                cnt++;
            }
            else {
                if (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') {
                    res *= dp4[cnt];
                }
                else {
                    res *= dp3[cnt];
                }
                res %= MOD;
                cnt = 1;
            }
        }
        if (pressedKeys[n - 1] == '7' || pressedKeys[n - 1] == '9') {
            res *= dp4[cnt];
        }
        else {
            res *= dp3[cnt];
        }
        res %= MOD;
        return res;
    }
};