#pragma once
using namespace std;
#include <vector>

/*
    ��һ�����У�����һ���ڵ���������������б�ɾ����ʣ�ಿ�����Ϊ���÷ǿ�������
    ԭ�ڵ�������������������Ըýڵ�Ϊ���ڵ�������Ƴ����γɵ�����
*/
class Solution {
public:
    long maxScore = 0;
    int cnt = 0;
    int n;
    vector<vector<int>> children;

    //ʹ���������������������ÿ���ڵ�Ϊ���ڵ�������Ĵ�С��ͬʱҲͳ�Ʒ���
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

        //ͳ��ÿ���ڵ���ӽڵ�
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