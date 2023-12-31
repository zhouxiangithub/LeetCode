#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        auto get = [&](int i)->pair<int, int> {
            if (i == -1 || i == n)
            {
                return { 0,0 };
            }
            return { 1,nums[i] };
        };

        int left = 0, right = n - 1, ans = -1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (get(mid) > get(mid - 1) && get(mid) > get(mid + 1))
            {
                ans = mid;
                break;
            }

            if (get(mid) < get(mid + 1))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
        {
            return 0;
        }

        int left = 0, right = n - 1, ans = -1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;

            if ((mid == 0 && nums[mid] > nums[mid + 1]) || (mid == n - 1 && nums[mid] > nums[mid - 1]) || (mid > 0 && mid<n - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]))
            {
                ans = mid;
                break;
            }

            if (nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};