#pragma once
using namespace std;

/*
    0
    01
    0110
    01101001
    每一行的后半部分正好为前半部分的"翻转"且每一行的前半部分和上一行相同
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (k == 1)
        {
            return 0;
        }
        if (k > (1 << (n - 2))) //k在这一行的后半部分
        {
            return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2)));
        }
        return kthGrammar(n - 1, k); //k在这一行的前半部分
    }
};