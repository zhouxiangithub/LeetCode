#pragma once
using namespace std;
#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <map>

/*
    �����е�ÿ���ڵ�洢һ���ַ�������keys����һ��������count����ʾkeys�е��ַ���������count�Ρ�
    �����ͷ��β��ÿ���ڵ��countֵ��������������һ���������ġ�
    ÿ���ڵ㻹��洢ָ����һ���ڵ��ָ��prev��ָ����һ���ڵ��ָ��next��
    ��һ����ϣ��nodesά��ÿ���ַ�����ǰ����������ڵ㡣
*/
class AllOne {
    list<pair<unordered_set<string>, int>> list_;
    unordered_map<string, std::list<pair<unordered_set<string>, int>>::iterator> nodes;
public:
    AllOne() {

    }

    void inc(string key) {
        if (nodes.count(key))
        {
            auto cur = nodes[key], next_ = next(cur); //std::next�Ĳ����ǵ�����
            if (next_ == list_.end() || next_->second > cur->second + 1)
            {
                unordered_set<string> s({ key });
                nodes[key] = list_.emplace(next_, s, cur->second + 1);
            }
            else
            {
                next_->first.emplace(key);
                nodes[key] = next_;
            }
            cur->first.erase(key);
            if (cur->first.empty())
            {
                list_.erase(cur);
            }
        }
        else
        {
            if (list_.empty() || list_.begin()->second > 1)
            {
                unordered_set<string> s({ key });
                list_.emplace_front(s, 1);
            }
            else
            {
                list_.begin()->first.emplace(key);
            }
            nodes[key] = list_.begin();
        }
    }

    void dec(string key) {
        auto cur = nodes[key];
        if (cur->second == 1)
        {
            nodes.erase(key);
        }
        else
        {
            auto prev_ = prev(cur);
            if (cur == list_.begin() || prev_->second < cur->second - 1)
            {
                unordered_set<string> s({ key });
                nodes[key] = list_.emplace(cur, s, cur->second - 1);
            }
            else
            {
                prev_->first.emplace(key);
                nodes[key] = prev_;
            }
        }
        cur->first.erase(key);
        if (cur->first.empty())
        {
            list_.erase(cur);
        }
    }

    string getMaxKey() {
        return list_.empty() ? "" : *list_.rbegin()->first.begin();
    }

    string getMinKey() {
        return list_.empty() ? "" : *list_.begin()->first.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

class AllOne {
    unordered_map<string, int> map_str; //�ַ���--���ִ���
    map<int, unordered_set<string>> map_strs; //���ִ���--�ַ�������
public:
    AllOne() {
    
    }

    void inc(string key) {
        if (map_strs.find(map_str[key]) != map_strs.end())
        {
            map_strs[map_str[key]].erase(key);
            if (map_strs[map_str[key]].empty())
            {
                map_strs.erase(map_str[key]);
            }
        }
        map_str[key]++;
        map_strs[map_str[key]].insert(key);
    }

    void dec(string key) {
        map_strs[map_str[key]].erase(key);
        if (map_strs[map_str[key]].empty())
        {
            map_strs.erase(map_str[key]);
        }
        map_str[key]--;
        if (!map_str[key])
        {
            map_str.erase(key);
        }
        else
        {
            map_strs[map_str[key]].insert(key);
        }
    }

    string getMaxKey() {
        return map_str.empty() ? "" : *(map_strs.rbegin()->second.begin());
    }

    string getMinKey() {
        return map_str.empty() ? "" : *(map_strs.begin()->second.begin());
    }
};