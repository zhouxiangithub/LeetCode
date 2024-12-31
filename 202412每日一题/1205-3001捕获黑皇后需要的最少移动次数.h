#pragma once
using namespace std;
#include <algorithm>

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // ����ʺ���ͬһ�У����м�û����
        if (a == e && (c != a || d < min(b, f) || d > max(b, f))) {
            return 1;
        }

        // ����ʺ���ͬһ�У����м�û����
        if (b == f && (d != b || c < min(a, e) || c > max(a, e))) {
            return 1;
        }

        // ����ʺ���ͬһ���Խ��ߣ����м�û�г�
        if (abs(c - e) == abs(d - f) && ((c - e) * (b - f) != (a - e) * (d - f) || a<min(c, e) || a>max(c, e))) {
            return 1;
        }

        return 2;
    }
};