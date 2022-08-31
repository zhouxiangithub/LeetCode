#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

/*
    如果一个数组能分为两块，那么一定能找到一个下标k，这个下标将数组分为两个非空子数组
    使得arr[0,...,k]和sortedArr[0,...,k]的元素频次相同，arr[k+1,...,n-1]和sortedArr[k+1,...,n-1]的元素频次也相同
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int, int> cnt; //记录两个数组元素频次之差
        int res = 0;
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < sortedArr.size(); i++)
        {
            int x = arr[i], y = sortedArr[i];
            cnt[x]++;
            if (cnt[x] == 0)
            {
                cnt.erase(x);
            }
            cnt[y]--;
            if (cnt[y] == 0)
            {
                cnt.erase(y);
            }
            if (cnt.size() == 0)
            {
                res++;
            }
        }
        return res;
    }
};

//单调栈
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st; //存储块的最大值
        for (auto& num : arr)
        {
            if (st.empty() || num >= st.top())
            {
                st.emplace(num);
            }
            else
            {
                int mx = st.top();
                st.pop();
                while (!st.empty() && st.top() > num)
                {
                    st.pop();
                }
                st.emplace(mx);
            }
        }
        return st.size();
    }
};