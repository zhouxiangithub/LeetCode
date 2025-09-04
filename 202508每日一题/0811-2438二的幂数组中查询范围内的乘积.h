#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    static const int mod = 1000000007;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> nums;
        int num = 1;
        while (n) {
            if (n % 2 == 1) {
                nums.push_back(num);
            }
            n >>= 1;
            num *= 2;
        }

        vector<int> res;
        for (const auto& query : queries) {
            int mul = 1;
            for (int i = query[0]; i <= query[1]; i++) {
                mul = static_cast<long long>(mul) * nums[i] % mod;
            }
            res.push_back(mul);
        }
        return res;
    }
};