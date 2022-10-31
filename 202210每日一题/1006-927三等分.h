#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0)
        {
            return { -1,-1 };
        }
        if (sum == 0)
        {
            return { 0,2 };
        }

        int partial = sum / 3;
        //第一个1出现的位置first, 第 partial+1 个1出现的位置second, 第 2*partial+1 个1出现的位置third, 区间[third, arr.length-1]所表示的二进制值是固定的
        int first = 0, second = 0, third = 0, cur = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 1)
            {
                if (cur == 0)
                {
                    first = i;
                }
                else if (cur == partial)
                {
                    second = i;
                }
                else if (cur == 2 * partial)
                {
                    third = i;
                }
                cur++;
            }
        }

        //设len=arr.length-1-third+1=arr.length-third, 三段:[first,first+len),[second,second+len),[third,third+len)
        int len = arr.size() - third;
        if (first + len <= second && second + len <= third)
        {
            int i = 0;
            while (third + i < arr.size())
            {
                if (arr[first + i] != arr[second + i] || arr[first + i] != arr[third + i])
                {
                    return { -1,-1 };
                }
                i++;
            }
            return { first + len - 1,second + len };
        }
        return { -1,-1 };
    }
};