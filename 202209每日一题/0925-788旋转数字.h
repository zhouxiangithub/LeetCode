#pragma once
using namespace std;
#include <string>

/*
    һ�����Ǻ��������ҽ�����
        ����û�г���3��4��7         // -1
        �������ٳ���һ��2��5��6��9  // 1
        0��1��8��ת�������Լ�      // 0
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