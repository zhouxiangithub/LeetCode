#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    vector<string_view> split(string& str, char ch)
    {
        int pos = 0;
        int start = 0;
        string_view s(str);
        vector<string_view> ret;
        while (pos < s.size())
        {
            while (pos < s.size() && s[pos] == ch)
            {
                pos++;
            }
            start = pos;
            while (pos < s.size() && s[pos] != ch)
            {
                pos++;
            }
            if (start < s.size())
            {
                ret.emplace_back(s.substr(start, pos - start));
            }
        }
        return ret;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string_view> dictionarySet;
        for (auto& root : dictionary)
        {
            dictionarySet.emplace(root);
        }
        vector<string_view> words = split(sentence, ' ');
        for (auto& word : words)
        {
            for (int j = 0; j < word.size(); j++)
            {
                if (dictionarySet.count(word.substr(0, j + 1)))
                {
                    word = word.substr(0, j + 1);
                    break;
                }
            }
        }
        string ans;
        for (int i = 0; i < words.size() - 1; i++)
        {
            ans.append(words[i]);
            ans.append(" ");
        }
        ans.append(words.back());
        return ans;
    }
};

//×ÖµäÊ÷
struct Trie
{
    unordered_map<char, Trie*> children;
};

class Solution {
public:
    vector<string> split(string& str, char ch)
    {
        int pos = 0;
        int start = 0;
        string_view s(str);
        vector<string> ret;
        while (pos < s.size())
        {
            while (pos < s.size() && s[pos] == ch)
            {
                pos++;
            }
            start = pos;
            while (pos < s.size() && s[pos] != ch)
            {
                pos++;
            }
            if (start < s.size())
            {
                ret.emplace_back(s.substr(start, pos - start));
            }
        }
        return ret;
    }

    string findRoot(string& word, Trie* trie)
    {
        string root;
        Trie* cur = trie;
        for (char& c : word)
        {
            if (cur->children.count('#'))
            {
                return root;
            }
            if (!cur->children.count(c))
            {
                return word;
            }
            root.push_back(c);
            cur = cur->children[c];
        }
        return root;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for (auto& word : dictionary)
        {
            Trie* cur = trie;
            for (char& c : word)
            {
                if (!cur->children.count(c))
                {
                    cur->children[c] = new Trie();
                }
                cur = cur->children[c];
            }
            cur->children['#'] = new Trie();
        }
        vector<string> words = split(sentence, ' ');
        for (auto& word : words)
        {
            word = findRoot(word, trie);
        }
        string ans;
        for (int i = 0; i < words.size() - 1; i++)
        {
            ans.append(words[i]);
            ans.append(" ");
        }
        ans.append(words.back());
        return ans;
    }
};