#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();

        auto check = [&](int m)->bool {
            vector<int> countA(26);
            for (int j = 0; j < n; j += m) {
                vector<int> countB(26);
                for (int k = j; k < j + m; k++) {
                    countB[s[k] - 'a']++;
                }
                if (j > 0 && countA != countB) {
                    return false;
                }
                countA.swap(countB);
            }
            return true;
        };

        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0) {
                continue;
            }
            if (check(i)) {
                return i;
            }
        }
        return n;
    }
};