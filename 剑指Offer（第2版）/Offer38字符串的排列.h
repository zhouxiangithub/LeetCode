#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

//»ØËÝ
class Solution
{
public:
	vector<string> ans;
	vector<int> vis;

	void backtrack(const string& s, int i, int n, string& perm)
	{
		if (i == n)
		{
			ans.push_back(perm);
			return;
		}
		for (int j = 0; j < n; j++)
		{
			if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j]))
			{
				continue;
			}
			vis[j] = true;
			perm.push_back(s[j]);
			backtrack(s, i + 1, n, perm);
			perm.pop_back();
			vis[j] = false;
		}
	}

	vector<string> permutation(string s)
	{
		int n = s.size();
		vis.resize(n);
		sort(s.begin(), s.end());
		string perm;
		backtrack(s, 0, n, perm);
		return ans;
	}
};