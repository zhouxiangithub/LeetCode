#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

struct TrieNode //前缀树
{
	string word;
	unordered_map<char, TrieNode*> children;
	TrieNode()
	{
		this->word = "";
	}
};

void insertTrie(TrieNode* root, const string& word)
{
	TrieNode* node = root;
	for (auto c : word)
	{
		if (!node->children.count(c))
		{
			node->children[c] = new TrieNode();
		}
		node = node->children[c];
	}
	node->word = word;
}

class Solution
{
public:
	int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

	bool dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, set<string>& res)
	{
		char ch = board[x][y];
		if (!root->children.count(ch))
		{
			return false;
		}
		root = root->children[ch];
		if (root->word.size() > 0)
		{
			res.insert(root->word);
			root->word = ""; //删除被匹配的单词，避免大量重复
		}

		board[x][y] = '#'; //同一个单元格内的字母在一个单词中不允许被重复使用
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dirs[i][0];
			int ny = y + dirs[i][1];
			if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
			{
				if (board[nx][ny] != '#')
				{
					dfs(board, nx, ny, root, res);
				}
			}
		}
		board[x][y] = ch; //将经过的单元格的字母临时修改后复原

		return true;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		TrieNode* root = new TrieNode();
		set<string> res;
		vector<string> ans;

		for (auto& word : words)
		{
			insertTrie(root, word);
		}
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				dfs(board, i, j, root, res);
			}
		}
		for (auto& word : res)
		{
			ans.emplace_back(word);
		}

		return ans;
	}
};