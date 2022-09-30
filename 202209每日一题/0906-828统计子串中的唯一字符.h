#pragma once
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

/*
    �ֱ����ÿ���ַ��Ĺ��ף���ÿ���ַ��������ж����ַ������������ַ�һ�μ��ɡ�
    �����±�Ϊi���ַ�c������һ�γ��ֵ�λ��Ϊj����һ�γ��ֵ�λ��Ϊk����ô���������ַ���һ���У�(i-j)*(k-i) �֡�
*/
class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> index;
        //Ԥ����s������ͬ�ַ����±����������
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