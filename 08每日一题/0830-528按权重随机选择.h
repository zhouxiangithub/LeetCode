#pragma once
using namespace std;
#include <vector>
#include <random>
#include <numeric>
#include <iterator>

/*2021-08-30*/
class Solution
{
private:
	mt19937 gen; //随机数
	uniform_int_distribution<int> dis; //离散均匀分布，它返回的是均匀分布在闭合范围[a,b]内的随机整数
	vector<int> prefixSum; //前缀和
public:
	/*
		random_device：提供()操作符，用来返回一个min()到max()之间的一个数
		accumulate：带有三个形参，前两个形参指定要累加的元素范围，第三个形参则是累加的初始值
		partial_sum：计算输入序列中长度从1开始不断增加的序列的和，并将结果保存到一个输出序列中
		back_inserter：插入迭代器是指被绑定在一个容器上，可以用来向容器中插入元素的迭代器
	*/
	Solution(vector<int>& w) :gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0))
	{
		partial_sum(w.begin(), w.end(), back_inserter(prefixSum));
	}

	//lower_bound：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin，得到找到数字在数组中的下标。
	int pickIndex()
	{
		int x = dis(gen);
		return lower_bound(prefixSum.begin(), prefixSum.end(), x) - prefixSum.begin();
	}
};