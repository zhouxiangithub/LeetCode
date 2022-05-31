#pragma once
using namespace std;
#include <vector>
#include <numeric>

/*
    �������СΪn
    ������nums�ֳɶ���飬ÿ�����СΪsize����ô�������Ϊ��n/size ����ȡ��
    ��һ������sum����ÿ�����Ԫ�غ�
    sumRange������ʱ�临�Ӷ�Ϊ��O(size+n/size)����ȡsize=sqrt(n)ʱ��ʱ�临�Ӷ�ΪO(sqrt(n))
*/
class NumArray {
private:
    vector<int> sum; //sum[i]��ʾ��i�����Ԫ�غ�
    int size; //��Ĵ�С
    vector<int>& nums;
public:
    //���캯����������Сsize����ʼ��sum
    NumArray(vector<int>& nums) : nums(nums) {
        int n = nums.size();
        size = sqrt(n);
        sum.resize((n - 1) / size + 1); // n/size ����ȡ��
        for (int i = 0; i < n; i++)
        {
            sum[i / size] += nums[i];
        }
    }

    //�±�index��Ӧ�Ŀ��±�Ϊ��index/size ����ȡ��������nums��sum
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