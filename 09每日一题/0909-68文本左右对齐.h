#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution
{
public:
	//返回长度为n的由空格组成的字符串
	string blank(int n)
	{
		return string(n, ' ');
	}

	//返回用sep拼接[left,right)范围内的words组成的字符串
	string join(vector<string>& words, int left, int right, string sep)
	{
		string s = words[left];
		for (int i = left + 1; i < right; i++)
		{
			s += sep + words[i];
		}
		return s;
	}

	vector<string> fullJustify(vector<string>& words, int maxWidth)
	{
		vector<string> ans;
		int right = 0, n = words.size();
		while (true)
		{
			int left = right; //当前行的第一个单词在words的位置
			int sumLen = 0; //统计这一行单词长度之和
			//循环确定当前行可以放多少单词，注意单词之间应该至少有一个空格
			while (right < n && sumLen + words[right].length() + right - left <= maxWidth)
			{
				sumLen += words[right++].length();
			}

			//当前行是最后一行：单词左对齐，且单词之间应该只有一个空格，在行末填充剩余空格
			if (right == n)
			{
				string s = join(words, left, n, " ");
				ans.emplace_back(s + blank(maxWidth - s.length()));
				return ans;
			}

			int numWords = right - left;
			int numSpaces = maxWidth - sumLen;

			//当前行只有一个单词：该单词左对齐，在行末填充剩余空格
			if (numWords == 1)
			{
				ans.emplace_back(words[left] + blank(numSpaces));
				continue;
			}

			//当前行不只一个单词
			int avgSpaces = numSpaces / (numWords - 1);
			int extraSpaces = numSpaces % (numWords - 1);

			//前 extraSpaces 个单词之间填充 avgSpaces+1 个空格，其余单词之间填充 avgSpaces 个空格
			string s1 = join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1));
			string s2 = join(words, left + extraSpaces + 1, right, blank(avgSpaces));

			ans.emplace_back(s1 + blank(avgSpaces) + s2);
		}
	}
};