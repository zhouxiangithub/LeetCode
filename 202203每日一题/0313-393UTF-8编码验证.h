#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    static const int MASK1 = 1 << 7;
    static const int MASK2 = (1 << 7) + (1 << 6);

    //10xxxxxx
    bool isValid(int num)
    {
        return (num & MASK2) == MASK1;
    }

    //0xxxxxxx��һ�ֽڵ����ֽ�
    //110xxxxx�����ֽڵ����ֽ�
    int getBytes(int num)
    {
        if ((num & MASK1) == 0)
        {
            return 1;
        }
        int n = 0;
        int mask = MASK1;
        while ((num & mask) != 0)
        {
            n++;
            if (n > 4)
            {
                return -1;
            }
            mask >>= 1;
        }
        return n >= 2 ? n : -1;
    }

    bool validUtf8(vector<int>& data) {
        int len = data.size();
        int index = 0;
        while (index < len)
        {
            int num = data[index];
            int n = getBytes(num); //����ÿ����Ч��UTF-8��������ֽ��жϰ����˶��ٸ��ֽ���
            
            if (n<0 || index + n>len)
            {
                return false;
            }

            //�жϳ����ֽ���������ֽ��Ƿ�Ϊ��Ч����
            for (int i = 1; i < n; i++)
            {
                if (!isValid(data[index + i]))
                {
                    return false;
                }
            }

            index += n;
        }
        return true;
    }
};