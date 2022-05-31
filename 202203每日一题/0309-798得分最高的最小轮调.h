#pragma once
using namespace std;
#include <vector>

/*
    ����nums[i]���÷ֵ��±귶Χ��[nums[i],n-1]�����䳤��Ϊ��n-nums[i]
    ������k�ֵ�����i ==> (i+n-k)%n
    ��Ҫ�÷֣���(i+n-k)%n >= nums[i]������k<=(i+n-nums[i])%n
    ���ǵ÷ֵ�kֵ��ΧΪ��(i+1)%n <= k <= (i+n-nums[i])%n
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