#pragma once
using namespace std;

//反向计算
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) //只有当tx不等于ty时才存在上一个状态，且上一个状态唯一
        {
            if (tx > ty) //如果tx>ty，则上一个状态是(tx-ty,ty)
            {
                tx %= ty;
            }
            else //如果tx<ty，则上一个状态是(tx,ty-tx)
            {
                ty %= tx;
            }
        }
        if (tx == sx && ty == sy)
        {
            return true;
        }
        else if (tx == sx)
        {
            return (ty > sy) && (ty - sy) % tx == 0;
        }
        else if (ty == sy)
        {
            return (tx > sx) && (tx - sx) % ty == 0;
        }
        else
        {
            return false;
        }
    }
};