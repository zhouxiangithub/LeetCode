#pragma once
using namespace std;
#include <vector>

/*2021-08-31*/
class Solution
{
public:
	//≥¨ ±¡À
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
	{
		vector<int> answer(n);
		for (auto& booking : bookings)
		{
			for (int i = booking[0]; i <= booking[1]; i++)
			{
				answer[i - 1] += booking[2];
			}
		}
		return answer;
	}

	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
	{
		vector<int> answer(n);
		for (auto& booking : bookings)
		{
			answer[booking[0] - 1] += booking[2];
			if (booking[1] < n)
			{
				answer[booking[1]] -= booking[2];
			}
		}
		for (int i = 1; i < n; i++)
		{
			answer[i] += answer[i - 1];
		}
		return answer;
	}
};