#pragma once
using namespace std;
#include <queue>

//模拟+队列
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> qu;
        for (int i = 1; i <= n; i++)
        {
            qu.emplace(i);
        }
        while (qu.size() > 1)
        {
            for (int i = 1; i < k; i++)
            {
                qu.emplace(qu.front());
                qu.pop();
            }
            qu.pop();
        }
        return qu.front();
    }
};

/*
    n=6,k=5
    old: 1 2 3 4 5 6 (1 2 3 4)
    new:           1  2 3 4 5
    new = (old - 5) mod 6
    new = (old - k) mod n
    ==> old - k = t*n + new 
    ==> old = (new+k) mod n
    注意到下标是以1开始的，所以：old = (new+k-1)%n+1
*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
        {
            return 1;
        }
        return (findTheWinner(n - 1, k) + k - 1) % n + 1;
    }
};

//迭代
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; i++)
        {
            winner = (winner + k - 1) % i + 1;
        }
        return winner;
    }
};