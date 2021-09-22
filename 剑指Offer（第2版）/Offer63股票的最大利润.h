#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	//³¬Ê±
	int maxProfit(vector<int>& prices)
	{
		int ans = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = i + 1; j < prices.size(); j++)
			{
				ans = max(ans, prices[j] - prices[i]);
			}
		}
		return ans;
	}

	int maxProfit(vector<int>& prices)
	{
		int min_p = INT_MAX, max_p = 0;
		for (int price : prices)
		{
			max_p = max(max_p, price - min_p);
			min_p = min(min_p, price);
		}
		return max_p;
	}
};