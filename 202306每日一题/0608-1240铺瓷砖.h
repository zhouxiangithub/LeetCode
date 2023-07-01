#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <functional>

class Solution {
public:
    int ans = 0;
    int tilingRectangle(int n, int m) {
        ans = max(n, m);
        vector<vector<bool>> rect(n, vector<bool>(m, false));
        dfs(0, 0, rect, 0);
        return ans;
    }

    void dfs(int x, int y, vector<vector<bool>>& rect, int cnt)
    {
        int n = rect.size(), m = rect[0].size();
        if (cnt >= ans)
        {
            return;
        }
        if (x >= n)
        {
            ans = cnt;
            return;
        }
        //�����һ��
        if (y >= m)
        {
            dfs(x + 1, 0, rect, cnt);
            return;
        }
        //�統ǰ�Ѿ�������,��ֱ�ӳ�����һ��λ��
        if (rect[x][y])
        {
            dfs(x, y + 1, rect, cnt);
            return;
        }
        for (int k = min(n - x, m - y); k >= 1 && isAvailable(rect, x, y, k); k--)
        {
            //������Ϊk�������������Ǹ���
            fillUp(rect, x, y, k, true);
            //����k��λ�ÿ�ʼ���
            dfs(x, y + k, rect, cnt + 1);
            fillUp(rect, x, y, k, false);
        }
    }

    bool isAvailable(vector<vector<bool>>& rect, int x, int y, int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (accumulate(rect[x + i].begin() + y, rect[x + i].begin() + y + k, false, bit_or()))
            {
                return false;
            }
        }
        return true;
    }

    void fillUp(vector<vector<bool>>& rect, int x, int y, int k, bool val)
    {
        for (int i = 0; i < k; i++)
        {
            fill(rect[x + i].begin() + y, rect[x + i].begin() + y + k, val);
        }
    }
};