#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	int minArray(vector<int>& numbers)
	{
		int len = numbers.size();
		for (int i = 0; i < len - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				return numbers[i + 1];
			}
		}
		return numbers[0];
	}

	int minArray(vector<int>& numbers)
	{
		int low = 0, high = numbers.size() - 1;
		while (low <= high)
		{
			int mid = (high - low) / 2 + low;
			if (numbers[mid] < numbers[high])
			{
				high = mid;
			}
			else if (numbers[mid] > numbers[high])
			{
				low = mid + 1;
			}
			else
			{
				high--;
			}
		}
		return numbers[low];
	}
};