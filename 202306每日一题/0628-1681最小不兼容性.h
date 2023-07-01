#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

/*
    x�Ķ����Ʊ�ʾ�ķǿ��Ӽ�y����:y&x=y
*/
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(1 << n, INT_MAX); //�Ѿ��������Ԫ�ؼ��ϵĲ�������֮��
        dp[0] = 0;
        int group = n / k; //�����黮�ֵ�k����ͬ��С���Ӽ���
        unordered_map<int, int> values;

        //Ԥ����:ɸѡ�����д�С�����������Ӽ�mask,������Ӽ���Ӧ�Ĳ������Ա����ڹ�ϣ����
        for (int mask = 1; mask < (1 << n); mask++)
        {
            if (__builtin_popcount(mask) != group)
            {
                continue;
            }
            int mmin = INT_MAX, mmax = INT_MIN;
            unordered_set<int> cur;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    if (cur.count(nums[i])) //ͬһ���Ӽ�����û��������ͬ��Ԫ��
                    {
                        break;
                    }
                    cur.insert(nums[i]);
                    mmin = min(mmin, nums[i]);
                    mmax = max(mmax, nums[i]);
                }
            }
            if (cur.size() == group)
            {
                values[mask] = mmax - mmin;
            }
        }

        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (dp[mask] == INT_MAX)
            {
                continue;
            }
            unordered_map<int, int> seen;
            for (int i = 0; i < n; i++)
            {
                if ((mask & (1 << i)) == 0)
                {
                    seen[nums[i]] = i;
                }
            }
            if (seen.size() < group)
            {
                continue;
            }
            int sub = 0; //����ÿһ��״̬mask,�����û�б������Ԫ�ؼ���sub
            for (auto& pair : seen)
            {
                sub |= (1 << pair.second);
            }
            int nxt = sub;
            while (nxt)
            {
                //����sub���Ӽ�nxt,����Ƿ��������,��Ϊ��һ�黮�ֵ�Ԫ�ؼ���
                if (values.count(nxt))
                {
                    dp[mask | nxt] = min(dp[mask | nxt], dp[mask] + values[nxt]);
                }
                nxt = (nxt - 1) & sub; //nxt��sub��һ���ǿ��Ӽ�
            }
        }

        return (dp[(1 << n) - 1] < INT_MAX) ? dp[(1 << n) - 1] : -1;
    }
};