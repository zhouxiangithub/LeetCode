#pragma once
using namespace std;
#include <string>

/*
    一个数是好数，当且仅当：
        数中没有出现3、4、7         // -1
        数中至少出现一次2或5或6或9  // 1
        0、1、8旋转后仍是自己      // 0
*/
class Solution {
private:
    static constexpr int check[10] = { 0,0,1,-1,-1,1,1,-1,0,1 };
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            string num = to_string(i);
            bool valid = true, diff = false;
            for (char ch : num)
            {
                if (check[ch - '0'] == -1)
                {
                    valid = false;
                }
                else if (check[ch - '0'] == 1)
                {
                    diff = true;
                }
            }
            if (valid && diff)
            {
                ans++;
            }
        }
        return ans;
    }
};