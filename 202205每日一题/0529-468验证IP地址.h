#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos)
        {
            //IPv4
            //存储相邻两个'.'出现的位置last和cur，queryIP[last+1..cur-1]
            int last = -1; //当考虑首个部分时，last=-1
            for (int i = 0; i < 4; i++)
            {
                int cur = (i == 3 ? queryIP.size() : queryIP.find('.', last + 1)); //当考虑最后一个部分时，cur=n
                if (cur == string::npos)
                {
                    return "Neither";
                }
                //长度判断
                if (cur - last - 1 < 1 || cur - last - 1 > 3)
                {
                    return "Neither";
                }
                int addr = 0;
                for (int j = last + 1; j < cur; j++)
                {
                    if (!isdigit(queryIP[j]))
                    {
                        return "Neither";
                    }
                    addr = addr * 10 + (queryIP[j] - '0');
                }
                //范围判断
                if (addr > 255)
                {
                    return "Neither";
                }
                //前导0判断
                if (addr > 0 && queryIP[last + 1] == '0')
                {
                    return "Neither";
                }
                if (addr == 0 && cur - last - 1 > 1)
                {
                    return "Neither";
                }
                last = cur;
            }
            return "IPv4";
        }
        else
        {
            //IPv6
            int last = -1;
            for (int i = 0; i < 8; i++)
            {
                int cur = (i == 7 ? queryIP.size() : queryIP.find(':', last + 1));
                if (cur == string::npos)
                {
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 4)
                {
                    return "Neither";
                }
                for (int j = last + 1; j < cur; j++)
                {
                    if (!isdigit(queryIP[j]) && !(towlower(queryIP[j]) >= 'a' && towlower(queryIP[j]) <= 'f'))
                    {
                        return "Neither";
                    }
                }
                last = cur;
            }
            return "IPv6";
        }
    }
};