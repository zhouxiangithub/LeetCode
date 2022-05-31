#pragma once
using namespace std;
#include <vector>

/*
    Jarvis �㷨��
        �������еĵ�r���ҵ����ڵ�p��˵��ʱ�뷽�����ĵ�q����������͹����
        �������2������Ե�p��ͬһ�����ϣ�Ӧ����q��pͬһ�߶��ϵı߽�㶼���ǽ�������ʱ��Ҫ���б�ǣ���ֹ�ظ���ӡ�
*/
class Solution {
public:
    //�������
    int cross(vector<int>& p, vector<int>& q, vector<int>& r)
    {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4)
        {
            return trees;
        }

        //�ҵ�����ߵĵ�
        int leftMost = 0;
        for (int i = 0; i < n; i++)
        {
            if (trees[i][0] < trees[leftMost][0])
            {
                leftMost = i;
            }
        }

        vector<vector<int>> res;
        vector<bool> visit(n, false);
        int p = leftMost;
        do
        {
            //�������еĵ�r���ҵ����ڵ�p��˵��ʱ�뷽�����ĵ�q
            int q = (p + 1) % n;
            for (int r = 0; r < n; r++)
            {
                //���r��pq���Ҳ࣬��q=r
                if (cross(trees[p], trees[q], trees[r]) < 0)
                {
                    q = r;
                }
            }

            //�Ƿ���ڵ�i��ʹ��p,q,i��ͬһ��ֱ����
            for (int i = 0; i < n; i++)
            {
                if (visit[i] || i == p || i == q)
                {
                    continue;
                }
                if (cross(trees[p], trees[q], trees[i]) == 0)
                {
                    res.emplace_back(trees[i]);
                    visit[i] = true;
                }
            }

            //����q����͹���У�������Ϊ�µĳ����㣬�ظ���������
            if (!visit[q])
            {
                res.emplace_back(trees[q]);
                visit[q] = true;
            }
            p = q;
        } while (p != leftMost);
        return res;
    }
};