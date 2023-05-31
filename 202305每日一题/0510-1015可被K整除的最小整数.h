#pragma once
using namespace std;
#include <unordered_set>

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 1 % k, len = 1;
        unordered_set<int> set;
        set.insert(remainder);
        while (remainder != 0)
        {
            remainder = (remainder * 10 + 1) % k;
            len++;
            if (set.find(remainder) != set.end()) //如果余数重复出现,则陷入循环,无解
            {
                return -1;
            }
            set.insert(remainder);
        }
        return len;
    }
};

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) //能被2或5整除,说明末尾一定不为1,无解
        {
            return -1;
        }
        int remainder = 1 % k, len = 1;
        //当k不为2或5的倍数时(与10互质),问题一定有解
        //假设n、m同余(n>m),则:k|(n-m),而n-m=11..1100..00,又k与10互质,所以:k|11..11,即问题一定有解
        while (remainder != 0)
        {
            remainder = (remainder * 10 + 1) % k;
            len++;
        }
        return len;
    }
};