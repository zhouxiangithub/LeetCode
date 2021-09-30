#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution
{
public:
	int findMinMoves(vector<int>& machines)
	{
		int total = accumulate(machines.begin(), machines.end(), 0);
		int n = machines.size();
		if (total % n)
		{
			return -1;
		}
		int avg = total / n;
		int ans = 0, sum = 0;
		for (int num : machines)
		{
			num -= avg;
			sum += num;
			ans = max(ans, max(abs(sum), num));
		}
		return ans;
	}
};