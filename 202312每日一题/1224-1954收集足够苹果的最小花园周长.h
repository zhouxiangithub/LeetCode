#pragma once
using namespace std;

//ÓÒÉÏ½Ç×ø±êÎª(n,n) ==> 2(2n+1)n(n+1) ==> 8n
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long left = 1, right = 100000, ans = 0;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples)
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return 8 * ans;
    }
};