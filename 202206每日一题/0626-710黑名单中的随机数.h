#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
    unordered_map<int, int> b2w;
    int bound;

public:
    //������[0,n-m)��Χ�ڵĺ������������ǿ��Խ���ӳ�䵽[n-m,n)��Χ�ڵİ�������
    Solution(int n, vector<int>& blacklist) {
        int m = blacklist.size();
        bound = n - m;
        unordered_set<int> black;
        for (int b : blacklist)
        {
            if (b >= bound)
            {
                black.emplace(b);
            }
        }

        int w = bound;
        for (int b : blacklist)
        {
            if (b < bound)
            {
                while (black.count(w))
                {
                    w++;
                }
                b2w[b] = w++;
            }
        }
    }

    int pick() {
        int x = rand() % bound;
        return b2w.count(x) ? b2w[x] : x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */