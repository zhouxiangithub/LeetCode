#pragma once
using namespace std;
#include <vector>

/*
    Jarvis 算法：
        遍历所有的点r，找到对于点p来说逆时针方向最靠外的点q，把它加入凸包。
        如果存在2个点相对点p在同一条线上，应当将q和p同一线段上的边界点都考虑进来，此时需要进行标记，防止重复添加。
*/
class Solution {
public:
    //向量叉积
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

        //找到最左边的点
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
            //遍历所有的点r，找到对于点p来说逆时针方向最靠外的点q
            int q = (p + 1) % n;
            for (int r = 0; r < n; r++)
            {
                //如果r在pq的右侧，则q=r
                if (cross(trees[p], trees[q], trees[r]) < 0)
                {
                    q = r;
                }
            }

            //是否存在点i，使得p,q,i在同一条直线上
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

            //将点q加入凸包中，并以它为新的出发点，重复上述操作
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