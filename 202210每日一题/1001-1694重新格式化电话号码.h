#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string reformatNumber(string number) {
        string digits;
        for (char ch : number)
        {
            if (isdigit(ch))
            {
                digits.push_back(ch);
            }
        }

        int n = digits.size();
        int index = 0;
        string ans;
        while (n)
        {
            if (n > 4)
            {
                ans += digits.substr(index, 3) + "-";
                index += 3;
                n -= 3;
            }
            else
            {
                if (n == 4)
                {
                    ans += digits.substr(index, 2) + "-" + digits.substr(index + 2, 2);
                }
                else
                {
                    ans += digits.substr(index, n);
                }
                break;
            }
        }

        return ans;
    }
};