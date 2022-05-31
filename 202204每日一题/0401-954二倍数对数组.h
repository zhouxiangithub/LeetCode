#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

/*
map��
�ŵ㣺
    �����ԣ�����map�ṹ�����ŵ㣬��Ԫ�ص��������ںܶ�Ӧ���ж���򻯺ܶ�Ĳ���
    ��������ڲ�ʵ��һ�������ʹ��map�ĺܶ������lgn��ʱ�临�Ӷ��¾Ϳ���ʵ�֣����Ч�ʷǳ��ĸ�
ȱ�㣺 
    �ռ�ռ���ʸߣ���Ϊmap�ڲ�ʵ���˺��������Ȼ���������Ч�ʣ�������Ϊÿһ���ڵ㶼��Ҫ���Ᵽ�游�ڵ㡢���ӽڵ�ͺ�/�����ʣ�
    ʹ��ÿһ���ڵ㶼ռ�ô����Ŀռ�
���ô���
    ������Щ��˳��Ҫ������⣬��map�����ЧһЩ

unordered_map��
�ŵ㣺
    ��Ϊ�ڲ�ʵ���˹�ϣ�����������ٶȷǳ��Ŀ�
ȱ�㣺
    ��ϣ��Ľ����ȽϺķ�ʱ��
���ô���
    ���ڲ������⣬unordered_map����Ӹ�ЧһЩ����������������⣬���ῼ��һ����unordered_map
*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        //cnt[i]��ʾarr��i�ĸ�������һ����ϣ����ͳ��cnt
        unordered_map<int, int> cnt;
        for (int i : arr)
        {
            cnt[i]++;
        }
        //����arr�е�0����ֻ����0ƥ�䣬���arr[0]���������򲻷�������
        if (cnt[0] % 2)
        {
            return false;
        }

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto& [i, _] : cnt) //C++17��չ�ƶϷ�Χ����
        {
            vals.emplace_back(i);
        }
        //��cnt�ļ�ֵ������ֵ��С�����˳������
        sort(vals.begin(), vals.end(), [](int a, int b) {return abs(a) < abs(b); });

        for (int i : vals)
        {
            if (cnt[2 * i] < cnt[i])
            {
                return false;
            }
            //��arr��ȥ��Ԫ�صĲ������Ը�Ϊ��cnt�м�ȥ��Ӧֵ
            cnt[2 * i] -= cnt[i];
            cnt[i] = 0;
        }
        return true;
    }
};