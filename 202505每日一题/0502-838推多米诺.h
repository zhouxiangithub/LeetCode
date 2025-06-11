#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), i = 0;
        char left = 'L';
        while (i < n) {
            int j = i;
            while (j < n && dominoes[j] == '.') {
                j++;
            }
            char cur = j < n ? dominoes[j] : 'R';
            if (left == cur) {
                while (i < j) {
                    dominoes[i++] = cur;
                }
            }
            else if (left == 'R' && cur == 'L') {
                int k = j - 1;
                while (i < k) {
                    dominoes[i++] = 'R';
                    dominoes[k--] = 'L';
                }
            }
            left = cur;
            i = j + 1;
        }
        return dominoes;
    }
};