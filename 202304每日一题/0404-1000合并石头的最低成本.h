#pragma once
using namespace std;
#include <vector>

class Solution {
    static constexpr int inf = 0x3f3f3f3f;
    vector<vector<vector<int>>> d;
    vector<int> sum;
    int k;
public:
    int get(int l, int r, int t)
    {
        if (d[l][r][t] != -1) //��Ϊ-1��ʾ�Ѿ���֮ǰ�ĵݹ鱻����,ֱ�ӷ��ؼ���
        {
            return d[l][r][t];
        }
        if (r - l + 1 < t) //��ʯͷ����С��tʱ,һ���޽�
        {
            return inf;
        }
        if (t == 1)
        {
            int res = get(l, r, k);
            if (res == inf)
            {
                return d[l][r][t] = inf;
            }
            return d[l][r][t] = res + (sum[r] - (l == 0 ? 0 : sum[l - 1]));
        }
        int val = inf;
        for (int p = l; p < r; p += (k - 1))
        {
            val = min(val, get(l, p, 1) + get(p + 1, r, t - 1));
        }
        return d[l][r][t] = val;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
        {
            return -1;
        }
        
        this->k = k;
        d = vector(n, vector(n, vector<int>(k + 1, -1)));
        sum = vector<int>(n, 0);

        for (int i = 0, s = 0; i < n; i++) //��ʼ��
        {
            d[i][i][1] = 0;
            s += stones[i];
            sum[i] = s;
        }
        
        int res = get(0, n - 1, 1);
        return res;
    }
};

class Solution {
    static constexpr int inf = 0x3f3f3f3f;
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
        {
            return -1;
        }

        vector d(n, vector(n, vector<int>(k + 1, inf)));
        vector<int> sum(n, 0);

        for (int i = 0, s = 0; i < n; i++) //��ʼ��
        {
            d[i][i][1] = 0;
            s += stones[i];
            sum[i] = s;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int l = 0; l < n && l + len - 1 < n; l++)
            {
                int r = l + len - 1;
                for (int t = 2; t <= k; t++)
                {
                    for (int p = l; p < r; p += k - 1)
                    {
                        d[l][r][t] = min(d[l][r][t], d[l][p][1] + d[p + 1][r][t - 1]);
                    }
                }
                d[l][r][1] = min(d[l][r][1], d[l][r][k] + sum[r] - (l == 0 ? 0 : sum[l - 1]));
            }
        }
        return d[0][n - 1][1];
    }
};

class Solution {
    static constexpr int inf = 0x3f3f3f3f;
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
        {
            return -1;
        }

        vector d(n, vector<int>(n, inf));
        vector<int> sum(n, 0);

        for (int i = 0, s = 0; i < n; i++) //��ʼ��
        {
            d[i][i] = 0;
            s += stones[i];
            sum[i] = s;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int l = 0; l < n && l + len - 1 < n; l++)
            {
                int r = l + len - 1;
                for (int p = l; p < r; p += k - 1)
                {
                    d[l][r] = min(d[l][r], d[l][p] + d[p + 1][r]);
                }
                if ((r - l) % (k - 1) == 0)
                {
                    d[l][r] += sum[r] - (l == 0 ? 0 : sum[l - 1]);
                }
            }
        }
        return d[0][n - 1];
    }
};
