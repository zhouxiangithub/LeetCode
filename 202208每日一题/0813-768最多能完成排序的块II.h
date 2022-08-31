#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

/*
    ���һ�������ܷ�Ϊ���飬��ôһ�����ҵ�һ���±�k������±꽫�����Ϊ�����ǿ�������
    ʹ��arr[0,...,k]��sortedArr[0,...,k]��Ԫ��Ƶ����ͬ��arr[k+1,...,n-1]��sortedArr[k+1,...,n-1]��Ԫ��Ƶ��Ҳ��ͬ
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int, int> cnt; //��¼��������Ԫ��Ƶ��֮��
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

//����ջ
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st; //�洢������ֵ
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