#pragma once
using namespace std;
#include <vector>

/*
* ������
		5
		/\
	   2  6
      /\
	 1  3
	���������132 6 5
	         i   m j(root)
	��������[i,m-1]
	��������[m,j-1]
*/
class Solution
{
public:
	bool verifyPostorder(vector<int>& postorder)
	{
		return recur(postorder, 0, postorder.size() - 1);
	}

	bool recur(vector<int>& postorder, int i, int j)
	{
		if (i >= j)
		{
			return true;
		}
		int p = i;
		while (postorder[p] < postorder[j])
		{
			p++;
		}
		int m = p;
		while (postorder[p] > postorder[j])
		{
			p++;
		}
		return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
	}
};