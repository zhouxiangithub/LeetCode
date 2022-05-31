#pragma once
using namespace std;
#include <vector>

/*
    在一颗树中，当把一个节点和与它相连的所有边删除，剩余部分最多为三棵非空子树：
    原节点的左子树，右子树，以该节点为根节点的子树移除所形成的子树
*/
class Solution {
public:
    long maxScore = 0;
    int cnt = 0;
    int n;
    vector<vector<int>> children;

    //使用深度优先搜索来计算以每个节点为根节点的子树的大小，同时也统计分数
    int dfs(int node)
    {
        long score = 1;
        int remainSize = n - 1;
        for (int child : children[node])
        {
            int size = dfs(child);
            score *= size;
            remainSize -= size;
        }
        if (node != 0)
        {
            score *= remainSize;
        }
        if (score == maxScore)
        {
            cnt++;
        }
        else if (score > maxScore)
        {
            maxScore = score;
            cnt = 1;
        }
        return n - remainSize;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        this->n = parents.size();
        this->children = vector<vector<int>>(n);

        //统计每个节点的子节点
        for (int i = 0; i < n; i++)
        {
            int p = parents[i];
            if (p != -1)
            {
                children[p].emplace_back(i);
            }
        }
        
        dfs(0);
        return cnt;
    }
};