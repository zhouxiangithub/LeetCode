#pragma once
using namespace std;
#include <string>

class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                sum++;
            }
            else {
                //ÿ����������ж��ٺ����Ҫ�������ٴ�
                res += sum;
            }
        }
        return res;
    }
};