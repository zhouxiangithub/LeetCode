#pragma once
using namespace std;
#include <vector>
#include <string>
#include <functional>

class MagicDictionary {
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }

    bool search(string searchWord) {
        for (auto& word : words)
        {
            if (word.size() != searchWord.size())
            {
                continue;
            }
            int diff = 0;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] != searchWord[i])
                {
                    diff++;
                    if (diff > 1)
                    {
                        break;
                    }
                }
            }
            if (diff == 1)
            {
                return true;
            }
        }
        return false;
    }

private:
    vector<string> words;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

//字典树
struct Trie {
    bool is_finished;
    Trie* child[26];

    Trie()
    {
        is_finished = false;
        fill(begin(child), end(child), nullptr);
    }
};

class MagicDictionary {
public:
    MagicDictionary() {
        root = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for (auto& word : dictionary)
        {
            Trie* cur = root;
            for (char ch : word)
            {
                int idx = ch - 'a';
                if (!cur->child[idx])
                {
                    cur->child[idx] = new Trie();
                }
                cur = cur->child[idx];
            }
            cur->is_finished = true;
        }
    }

    bool search(string searchWord) {
        //当前遍历到的字典树上的节点是node，待查询字符串searchWord的第pos个字符，在之前的遍历中是否已经替换过恰好一个字符
        function<bool(Trie*, int, bool)> dfs = [&](Trie* node, int pos, bool modified)
        {
            if (pos == searchWord.size())
            {
                return modified && node->is_finished;
            }
            int idx = searchWord[pos] - 'a';
            if (node->child[idx])
            {
                if (dfs(node->child[idx], pos + 1, modified))
                {
                    return true;
                }
            }
            if (!modified)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (i != idx && node->child[i])
                    {
                        if (dfs(node->child[i], pos + 1, true))
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        return dfs(root, 0, false);
    }

private:
    Trie* root;
};