#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    并查集
    为了得到数组nums中的每个数和哪些数属于同一个组件，需要得到数组nums中的最大值m
    对于每个不超过m的正整数num计算num和哪些数属于同一个组件
*/
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    //初始时，每个数分别属于不同的组件
    UnionFind(int n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    /*
        如果两个正整数满足其中一个正整数是另一个正整数的因数，
        则这两个正整数属于同一个组件，将这两个正整数的组件合并。
    */
    void uni(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] > rank[rooty])
            {
                parent[rooty] = rootx;
            }
            else if (rank[rootx] < rank[rooty])
            {
                parent[rootx] = rooty;
            }
            else
            {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        UnionFind uf(m + 1);
        for (int num : nums)
        {
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    uf.uni(num, i);
                    uf.uni(num, num / i);
                }
            }
        }
        vector<int> counts(m + 1);
        int ans = 0;
        //遍历数组nums，对于每个数得到其所在的组件并更新该组件的大小
        for (int num : nums)
        {
            int root = uf.find(num);
            counts[root]++;
            ans = max(ans, counts[root]);
        }
        return ans;
    }
};