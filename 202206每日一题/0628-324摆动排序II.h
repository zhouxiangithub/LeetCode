#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    假设数组中元素的数目为n，则数组中相同元素的数目最多不超过: x=(n+1)/2
    反证法易证：假设相同元素数目大于该值，则必有相同的元素相邻，这将导致摆动排序无法完成

    首先将数组按照从小到大进行排序后，由于nums[i]不等于nums[i+x]，则一定有: nums[i]<nums[i+x]
    因此，我们可以得到：nums[0]<nums[x], nums[1]<nums[x+1],..., nums[i]<nums[i+x]

    当n为偶数时，可以将nums[i+x]插入到nums[i-1]与nums[i]之间：
    nums[x], nums[0], nums[x+1], nums[1],..., nums[n-2-x], nums[n-1], nums[n-1-x]
    然后将上述序列进行反转：
    nums[n-1-x], nums[n-1], nums[n-2-x],..., nums[1], nums[x+1], nums[0], nums[x]

    当n为奇数时，可以证明（反证法）当满足i>0时，nums[i]<nums[i+x-1]
    可以将nums[i+x]插入到nums[i]与nums[i+1]之间：
    nums[0], nums[x], nums[1],..., nums[n-1-x], nums[n-1], nums[n-x]
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--)
        {
            nums[i] = arr[j];
            if (i + 1 < n)
            {
                nums[i + 1] = arr[k];
            }
        }
    }
};