#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            int cnt = 0, sum = 0;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    cnt++;
                    sum += i;
                    if (i * i != num) {
                        cnt++;
                        sum += num / i;
                    }
                }
            }
            if (cnt == 4) {
                res += sum;
            }
        }
        return res;
    }
};