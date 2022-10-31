#pragma once
using namespace std;

/*
    0
    01
    0110
    01101001
    ÿһ�еĺ�벿������Ϊǰ�벿�ֵ�"��ת"��ÿһ�е�ǰ�벿�ֺ���һ����ͬ
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (k == 1)
        {
            return 0;
        }
        if (k > (1 << (n - 2))) //k����һ�еĺ�벿��
        {
            return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2)));
        }
        return kthGrammar(n - 1, k); //k����һ�е�ǰ�벿��
    }
};