#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

//ֻ��Ҫarr��targetԪ����ͬ��arr����ͨ�����ɴβ������target
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> count1, count2;
        for (int num : target)
        {
            count1[num]++;
        }
        for (int num : arr)
        {
            count2[num]++;
        }
        if (count1.size() != count2.size())
        {
            return false;
        }
        for (auto& [key, value] : count1)
        {
            if (!count2.count(key) || count2[key] != value)
            {
                return false;
            }
        }
        return true;
    }
};