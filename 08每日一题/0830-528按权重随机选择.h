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
	mt19937 gen; //�����
	uniform_int_distribution<int> dis; //��ɢ���ȷֲ��������ص��Ǿ��ȷֲ��ڱպϷ�Χ[a,b]�ڵ��������
	vector<int> prefixSum; //ǰ׺��
public:
	/*
		random_device���ṩ()����������������һ��min()��max()֮���һ����
		accumulate�����������βΣ�ǰ�����β�ָ��Ҫ�ۼӵ�Ԫ�ط�Χ���������β������ۼӵĳ�ʼֵ
		partial_sum���������������г��ȴ�1��ʼ�������ӵ����еĺͣ�����������浽һ�����������
		back_inserter�������������ָ������һ�������ϣ����������������в���Ԫ�صĵ�����
	*/
	Solution(vector<int>& w) :gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0))
	{
		partial_sum(w.begin(), w.end(), back_inserter(prefixSum));
	}

	//lower_bound���������beginλ�õ�end-1λ�ö��ֲ��ҵ�һ�����ڻ����num�����֣��ҵ����ظ����ֵĵ�ַ���������򷵻�end��ͨ�����صĵ�ַ��ȥ��ʼ��ַbegin���õ��ҵ������������е��±ꡣ
	int pickIndex()
	{
		int x = dis(gen);
		return lower_bound(prefixSum.begin(), prefixSum.end(), x) - prefixSum.begin();
	}
};