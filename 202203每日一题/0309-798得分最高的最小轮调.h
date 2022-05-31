#pragma once
using namespace std;
#include <vector>

/*
    对于nums[i]，得分的下标范围在[nums[i],n-1]，区间长度为：n-nums[i]
    若进行k轮调，则：i ==> (i+n-k)%n
    若要得分，则：(i+n-k)%n >= nums[i]，即：k<=(i+n-nums[i])%n
    于是得分的k值范围为：(i+1)%n <= k <= (i+n-nums[i])%n
*/
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diffs(n);
        for (int i = 0; i < n; i++)
        {
            int low = (i + 1) % n;
            int high = (i + n - nums[i] + 1) % n;
            diffs[low]++;
            diffs[high]--;
            if (low >= high)
            {
                diffs[0]++;
            }
        }
        int bestIndex = 0;
        int maxScore = 0;
        int score = 0;
        for (int i = 0; i < n; i++)
        {
            score += diffs[i];
            if (score > maxScore)
            {
                bestIndex = i;
                maxScore = score;
            }
        }
        return bestIndex;
    }
};