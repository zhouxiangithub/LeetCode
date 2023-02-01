#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    ����0,1,2���ܵ����б��,���obstacles[i]-1���ܵ���Ӧ,ֵ-1��ʾi�����ϰ�
    ����d[i][j]��ʾ���ܵ���i�ŵ��j���ܵ���������ٲ�������
    �������ܴӵ�0���ܵ�2����,�ҵ�0���͵�n������һ�ܵ������ϰ�
    ��: d[0][0]=1, d[0][1]=0, d[0][2]=1
*/
class Solution {
    static constexpr int inf = 0x3f3f3f3f;
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<int> d = { 1,0,1 };
        for (int i = 1; i <= n; i++)
        {
            int minCnt = inf;
            //ͬһ���ܵ�
            for (int j = 0; j < 3; j++)
            {
                if (j == obstacles[i] - 1) //���ϰ�
                {
                    d[j] = inf;
                }
                else
                {
                    minCnt = min(minCnt, d[j]);
                }
            }
            //���ܵ�
            for (int j = 0; j < 3; j++)
            {
                if (j == obstacles[i] - 1) //���ϰ�
                {
                    continue;
                }
                d[j] = min(d[j], minCnt + 1);
            }
        }
        return *min_element(d.begin(), d.end());
    }
};