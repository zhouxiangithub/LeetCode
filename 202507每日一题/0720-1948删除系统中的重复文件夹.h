#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <algorithm>

struct Trie {
    // ��ǰ�ڵ�ṹ�����л���ʾ
    string serial;
    // ��ǰ�ڵ���ӽڵ�
    unordered_map<string, Trie*> children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // ���ڵ�
        Trie* root = new Trie();

        for (const vector<string>& path : paths) {
            Trie* cur = root;
            for (const string& node : path) {
                if (!cur->children.count(node)) {
                    cur->children[node] = new Trie();
                }
                cur = cur->children[node];
            }
        }

        // ��ϣ���¼ÿһ�����л���ʾ�ĳ��ִ���
        unordered_map<string, int> freq;
        // ����������������ĺ������������ÿһ���ڵ�ṹ�����л���ʾ
        function<void(Trie*)> construct = [&](Trie* node) {
            // �����Ҷ�ڵ㣬��ô���л���ʾΪ���ַ�������������κβ���
            if (node->children.empty()) {
                return;
            }

            vector<string> v;
            // �������Ҷ�ڵ㣬��Ҫ�ȼ����ӽڵ�ṹ�����л���ʾ
            for (const auto& [folder, child] : node->children) {
                construct(child);
                v.push_back(folder + "(" + child->serial + ")");
            }
            // ��ֹ˳������⣬��Ҫ��������
            sort(v.begin(), v.end());
            for (string& s : v) {
                node->serial += move(s);
            }
            // �����ϣ��
            ++freq[node->serial];
        };

        construct(root);

        vector<vector<string>> res;
        // ��¼���ڵ㵽��ǰ�ڵ��·��
        vector<string> path;

        function<void(Trie*)> operate = [&](Trie* node) {
            // ������л���ʾ�ڹ�ϣ���г����˳��� 1 �Σ�����Ҫɾ��
            if (freq[node->serial] > 1) {
                return;
            }
            // ����·�������
            if (!path.empty()) {
                res.push_back(path);
            }
            for (const auto& [folder, child] : node->children) {
                path.push_back(folder);
                operate(child);
                path.pop_back();
            }
        };

        operate(root);
        return res;
    }
};