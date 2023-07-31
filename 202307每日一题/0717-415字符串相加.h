#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0)
        {
            int add1 = i >= 0 ? num1[i] - '0' : 0;
            int add2 = j >= 0 ? num2[j] - '0' : 0;
            int sum = add1 + add2 + add;
            ans.push_back('0' + sum % 10);
            add = sum / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};