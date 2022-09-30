#pragma once
using namespace std;
#include <vector>
#include <algorithm>

//��̬�滮������dp[i]Ϊ��pairs[i]Ϊ��β����������ĳ���
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};

//����������У�̰��+���ֲ���
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> arr; //arr[i]��ʾ����Ϊi+1����������ĩβ����ȡ�õ���Сֵ
        for (auto p : pairs)
        {
            int x = p[0], y = p[1];
            if (arr.size() == 0 || x > arr.back())
            {
                arr.emplace_back(y);
            }
            else
            {
                int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                arr[idx] = min(arr[idx], y);
            }
        }
        return arr.size();
    }
};

//̰�ģ���ѡ�ڶ���������С��
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int curr = INT_MIN, res = 0;
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; });
        for (auto& p : pairs)
        {
            if (curr < p[0])
            {
                curr = p[1];
                res++;
            }
        }
        return res;
    }
};