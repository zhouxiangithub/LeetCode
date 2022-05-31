#pragma once
using namespace std;

//�������
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) //ֻ�е�tx������tyʱ�Ŵ�����һ��״̬������һ��״̬Ψһ
        {
            if (tx > ty) //���tx>ty������һ��״̬��(tx-ty,ty)
            {
                tx %= ty;
            }
            else //���tx<ty������һ��״̬��(tx,ty-tx)
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