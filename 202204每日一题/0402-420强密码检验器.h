#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        bool has_lower = false, has_upper = false, has_digit = false;
        for (char ch : password)
        {
            if (islower(ch))
            {
                has_lower = true;
            }
            else if (isupper(ch))
            {
                has_upper = true;
            }
            else if (isdigit(ch))
            {
                has_digit = true;
            }
        }
        int categories = has_lower + has_upper + has_digit; //字符串中包含小写字母、大写字母和数字的种类

        //修改操作：插入、删除、替换
        if (n < 6)
        {
            //当字符串长度小于6时，同时要满足强密码字符条件（至少包含三种字符），最好的操作是插入（插入的同时可以增加字符串的长度）
            return max(6 - n, 3 - categories);
        }
        else if (n <= 20)
        {
            /*
                当字符串满足了强密码长度条件后，最好的操作是替换，假设有连续的k个相同的字符
                替换操作的次数为：所有的(k/3)之和与(3 - categories)中的较大值
            */
            int replace = 0;
            int cnt = 0;
            char cur = '#';
            for (char ch : password)
            {
                if (ch == cur)
                {
                    cnt++;
                }
                else
                {
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            replace += cnt / 3; //连续的字符出现在了原字符串的最后
            return max(replace, 3 - categories);
        }
        else
        {
            /*
                当字符串长度大于20时，为满足强密码长度条件，需要进行删除操作（减少长度）
                而当字符串长度满足要求后，接下来可能需要进行替换操作（若此时还存在至少3个连续相同的字符）

                替换操作的次数为：所有的(k/3)之和
                删除操作的次数为：(n-20)

                删除操作可以使得替换操作次数减少1：
                如果k%3=0，那么删除1个字符后，k/3的值会减少1，随后每删除3个字符，k/3的值会再减少1；
                如果k%3=1，那么删除2个字符后，k/3的值会减少1，随后每删除3个字符，k/3的值会再减少1；
                如果k%3=2，那么每删除3个字符，k/3的值会减少1；

                因此，删除的顺序是：
                (1)从所有k%3=0的连续相同字符组中删除1个字符；
                (2)从所有k%3=1的连续相同字符组中删除2个字符；
                (3)删除3个字符；
            */
            int replace = 0, remove = n - 20;
            int rm2 = 0;
            int cnt = 0;
            char cur = '#';
            for (char ch : password)
            {
                if (ch == cur)
                {
                    cnt++;
                }
                else
                {
                    if (remove > 0 && cnt >= 3)
                    {
                        if (cnt % 3 == 0)
                        {
                            remove--;
                            replace--;
                        }
                        else if (cnt % 3 == 1)
                        {
                            rm2++;
                        }
                    }
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }

            //连续的字符出现在了原字符串的最后
            if (remove > 0 && cnt >= 3)
            {
                if (cnt % 3 == 0)
                {
                    remove--;
                    replace--;
                }
                else if (cnt % 3 == 1)
                {
                    rm2++;
                }
            }
            replace += cnt / 3;

            //k%3=0在上述中已经讨论过了，接下来考虑k%3=1的情况：(2)从所有k%3=1的连续相同字符组中删除2个字符；
            int use2 = min(replace, min(rm2, remove / 2)); //删除2个字符的次数
            replace -= use2;
            remove -= use2 * 2;

            //其它，包含k%3=2的情况：(3)删除3个字符；
            int use3 = min(replace, remove / 3);
            replace -= use3;
            remove -= use3 * 3;

            return (n - 20) + max(replace, 3 - categories);
        }
    }
};