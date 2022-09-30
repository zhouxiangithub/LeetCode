#pragma once
using namespace std;
#include <unordered_set>
#include <numeric>

/*
    ���6k+1���ܰ�ť1��3��4Ӱ��
    ���6k+2,6k+6���ܰ�ť1��2Ӱ��
    ���6k+3,6k+5���ܰ�ť1��3Ӱ��
    ���6k+4���ܰ�ť1��2��4Ӱ��
    ��ˣ�ֻ��Ҫ�����ĸ����ݣ�����֪�����е��ݵ����״̬��
*/
class Solution {
public:
    int flipLights(int n, int presses) {
        unordered_set<int> seen;
        for (int i = 0; i < (1 << 4); i++)
        {
            vector<int> pressArr(4); //��ʾ4����ť�İ������
            for (int j = 0; j < 4; j++)
            {
                pressArr[j] = (i >> j) & 1;
            }
            int sum = accumulate(pressArr.begin(), pressArr.end(), 0);
            if (sum % 2 == presses % 2 && sum <= presses)
            {
                int status = pressArr[0] ^ pressArr[2] ^ pressArr[3];
                if (n >= 2)
                {
                    status |= (pressArr[0] ^ pressArr[1]) << 1;
                }
                if (n >= 3)
                {
                    status |= (pressArr[0] ^ pressArr[2]) << 2;
                }
                if (n >= 4)
                {
                    status |= (pressArr[0] ^ pressArr[1] ^ pressArr[3]) << 3;
                }
                seen.emplace(status);
            }
        }
        return seen.size();
    }
};