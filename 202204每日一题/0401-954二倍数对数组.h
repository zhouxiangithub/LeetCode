#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

/*
map：
优点：
    有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作
    红黑树，内部实现一个红黑书使得map的很多操作在lgn的时间复杂度下就可以实现，因此效率非常的高
缺点： 
    空间占用率高，因为map内部实现了红黑树，虽然提高了运行效率，但是因为每一个节点都需要额外保存父节点、孩子节点和红/黑性质，
    使得每一个节点都占用大量的空间
适用处：
    对于那些有顺序要求的问题，用map会更高效一些

unordered_map：
优点：
    因为内部实现了哈希表，因此其查找速度非常的快
缺点：
    哈希表的建立比较耗费时间
适用处：
    对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map
*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        //cnt[i]表示arr中i的个数，用一个哈希表来统计cnt
        unordered_map<int, int> cnt;
        for (int i : arr)
        {
            cnt[i]++;
        }
        //对于arr中的0，它只能与0匹配，如果arr[0]是奇数，则不符合条件
        if (cnt[0] % 2)
        {
            return false;
        }

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto& [i, _] : cnt) //C++17扩展推断范围遍历
        {
            vals.emplace_back(i);
        }
        //将cnt的键值按绝对值从小到大的顺序排列
        sort(vals.begin(), vals.end(), [](int a, int b) {return abs(a) < abs(b); });

        for (int i : vals)
        {
            if (cnt[2 * i] < cnt[i])
            {
                return false;
            }
            //从arr中去掉元素的操作可以改为从cnt中减去对应值
            cnt[2 * i] -= cnt[i];
            cnt[i] = 0;
        }
        return true;
    }
};