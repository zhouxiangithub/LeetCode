#pragma once
using namespace std;
#include <vector>
#include <numeric>

/*
    设数组大小为n
    将数组nums分成多个块，每个块大小为size，那么块的总数为：n/size 向上取整
    用一个数组sum保存每个块的元素和
    sumRange函数的时间复杂度为：O(size+n/size)，当取size=sqrt(n)时，时间复杂度为O(sqrt(n))
*/
class NumArray {
private:
    vector<int> sum; //sum[i]表示第i个块的元素和
    int size; //块的大小
    vector<int>& nums;
public:
    //构造函数，计算块大小size，初始化sum
    NumArray(vector<int>& nums) : nums(nums) {
        int n = nums.size();
        size = sqrt(n);
        sum.resize((n - 1) / size + 1); // n/size 向上取整
        for (int i = 0; i < n; i++)
        {
            sum[i / size] += nums[i];
        }
    }

    //下标index对应的块下标为：index/size 向下取整，更新nums和sum
    void update(int index, int val) {
        sum[index / size] += val - nums[index];
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        int b1 = left / size, i1 = left % size, b2 = right / size, i2 = right % size;
        if (b1 == b2)
        {
            return accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + i2 + 1, 0);
        }
        int sum1 = accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + size, 0);
        int sum2 = accumulate(nums.begin() + b2 * size, nums.begin() + b2 * size + i2 + 1, 0);
        int sum3 = accumulate(sum.begin() + b1 + 1, sum.begin() + b2, 0);
        return sum1 + sum2 + sum3;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */