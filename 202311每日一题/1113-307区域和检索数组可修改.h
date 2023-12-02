#pragma once
using namespace std;
#include <vector>
#include <numeric>

class NumArray {
private:
    vector<int> sum;
    int size;
    vector<int>& nums;

public:
    NumArray(vector<int>& nums) :nums(nums) {
        int n = nums.size();
        size = sqrt(n); //��Ĵ�С
        sum.resize((n + size - 1) / size); // n/size����ȡ��,��i�����Ԫ�غ�
        for (int i = 0; i < n; i++)
        {
            sum[i / size] += nums[i];
        }
    }

    void update(int index, int val) {
        sum[index / size] += val - nums[index];
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        int lblock = left / size, lblock_idx = left % size, rblock = right / size, rblock_idx = right % size;
        if (lblock == rblock) //��ͬһ������
        {
            return accumulate(nums.begin() + lblock * size + lblock_idx, nums.begin() + rblock * size + rblock_idx + 1, 0);
        }
        int sum1 = accumulate(nums.begin() + lblock * size + lblock_idx, nums.begin() + lblock * size + size, 0);
        int sum2 = accumulate(sum.begin() + lblock + 1, sum.begin() + rblock, 0);
        int sum3 = accumulate(nums.begin() + rblock * size, nums.begin() + rblock * size + rblock_idx + 1, 0);
        return sum1 + sum2 + sum3;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */