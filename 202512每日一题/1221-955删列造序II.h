#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        vector<bool> keep(A.size() - 1, false);

        for (int j = 0; j < A[0].length(); j++) {
            bool deleted = false;
            for (int i = 1; i < A.size(); i++) {
                if (!keep[i - 1] && A[i - 1][j] > A[i][j]) {
                    deleted = true;
                    break;
                }
            }

            if (deleted) {
                res++;
            }
            else {
                for (int i = 1; i < A.size(); i++) {
                    if (A[i - 1][j] < A[i][j]) {
                        keep[i - 1] = true;
                    }
                }
            }
        }

        return res;
    }
};