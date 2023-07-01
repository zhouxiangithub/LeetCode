#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence.back() != sentence.front())
        {
            return false;
        }
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ' && sentence[i + 1] != sentence[i - 1]) //�����κ�ǰ����β��ո�
            {
                return false;
            }
        }
        return true;
    }
};