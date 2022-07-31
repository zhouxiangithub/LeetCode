#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

/*
    �����ά����dp��ʾ��ÿ���±�Ե�Ԫ����Ϊ����������ֵ�쳲����������е���󳤶�
    ��i>jʱ��dp[j][i]��ʾ��arr[j]��arr[i]��Ϊ����������ֵ�쳲����������е���󳤶�

    arr[k] + arr[j] = arr[i], k<j<i

    ��dp[k][j]>=3ʱ��dp[j][i]=dp[k][j]+1
    ��dp[k][j]<3ʱ����arr[k]��arr[j]��Ϊ����������ֵ�쳲����������в������ڣ�
    ������arr[j]��arr[i]��Ϊ����������ֵ�쳲����������д��ڣ���ʱdp[j][i]=3

    dp[j][i] = max(dp[k][j]+1, 3), 0<=k<j
             = 0, k<0 or k>=j
    
    Ϊ������k<j��arr[k]<arr[j]����arr[i] = arr[k] + arr[j] < 2*arr[j]
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> indices;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            indices[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0 && 2 * arr[j] > arr[i]; j--) // k < j, arr[k] < arr[j]
            {
                int k = -1;
                if (indices.count(arr[i] - arr[j]))
                {
                    k = indices[arr[i] - arr[j]];
                }
                if (k >= 0)
                {
                    dp[j][i] = max(dp[k][j] + 1, 3);
                }
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};