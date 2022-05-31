#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b)
            {
                return a.size() != b.size() ? a.size() < b.size() : a > b;
            });
        string longest;
        unordered_set<string> candidates = { "" };
        for (const auto& word : words)
        {
            if (candidates.count(word.substr(0, word.size() - 1)))
            {
                candidates.emplace(word);
                longest = word;
            }
        }
        return longest;
    }
};

//×ÖµäÊ÷
class Trie
{
private:
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() 
    {
        this->children = vector<Trie*>(26, nullptr);
        this->isEnd = false;
    }

    void insert(const string& word)
    {
        Trie* node = this;
        for (const auto& ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(const string& word)
    {
        Trie* node = this;
        for (const auto& ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr || !node->children[index]->isEnd)
            {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const auto& word : words)
        {
            trie.insert(word);
        }
        string longest = "";
        for (const auto& word : words)
        {
            if (trie.search(word))
            {
                if (word.size() > longest.size() || (word.size() == longest.size() && word < longest))
                {
                    longest = word;
                }
            }
        }
        return longest;
    }
};