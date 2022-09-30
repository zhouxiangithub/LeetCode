#pragma once
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

/*
    分别计算每个字符的贡献：对每个字符，计算有多少字符串仅包含该字符一次即可。
    对于下标为i的字符c，记上一次出现的位置为j，下一次出现的位置为k，那么这样的子字符串一共有：(i-j)*(k-i) 种。
*/
class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> index;
        //预处理s，将相同字符的下标放入数组中
        for (int i = 0; i < s.size(); i++)
        {
            index[s[i]].emplace_back(i);
        }
        int res = 0;
        for (auto&& [_, arr] : index)
        {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(s.size());
            for (int i = 1; i < arr.size() - 1; i++)
            {
                res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return res;
    }
};