#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

/*2021-08-21*/
class Solution
{
public:
	int compress(vector<char>& chars)
	{
		int n = chars.size();
		int write = 0, left = 0;
		for (int read = 0; read < n; read++)
		{
			if (read == n - 1 || chars[read] != chars[read + 1])
			{
				chars[write++] = chars[read];
				int num = read - left + 1;
				if (num > 1)
				{
					int anchor = write;
					while (num > 0)
					{
						chars[write++] = num % 10 + '0';
						num /= 10;
					}
					reverse(&chars[anchor], &chars[write]);
				}
				/*if (num > 1)
				{
					string str = std::to_string(num);
					for (int i = 0; i < str.length(); i++)
					{
						chars[write++] = str[i];
					}
				}*/
				left = read + 1;
			}
		}
		return write;
	}
};
