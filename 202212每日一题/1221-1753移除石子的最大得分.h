#pragma once
using namespace std;
#include <algorithm>

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int maxVal = max(a, max(b, c));
        //≤ª∑¡…Ëa<=b<=c
        if (sum - maxVal < maxVal) //a+b<=c
        {
            return sum - maxVal; 
        }
        else //a+b>c=k1+k2, res=(k1+k2)+[(a-k1)+(b-k2)]/2=sum/2
        {
            return sum / 2;
        }
    }
};