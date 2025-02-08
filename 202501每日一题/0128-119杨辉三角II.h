#pragma once
using namespace std;
#include <vector>

/*
    C(n,m) = n!/[m!¡¤(n-m)!]
    C(n,m-1) = n!/[(m-1)!¡¤(n-m+1)!]

    C(n,m)*m/(n-m+1) = C(n,m-1)
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int m = 1; m <= rowIndex; m++) {
            res[m] = 1LL * res[m - 1] * (rowIndex - m + 1) / m;
        }
        return res;
    }
};