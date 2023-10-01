#pragma once
using namespace std;
#include <unordered_map>
#include <set>

struct Node
{
    int cnt, time, key, value;
    Node(int _cnt, int _time, int _key, int _value) :cnt(_cnt), time(_time), key(_key), value(_value) {}
    bool operator<(const Node& node) const {
        return cnt == node.cnt ? time < node.time : cnt < node.cnt;
    }
};

class LFUCache {
private:
    int cap, time;
    unordered_map<int, Node> cache;
    set<Node> nodeSet;

public:
    LFUCache(int capacity) {
        cap = capacity;
        time = 0;
        cache.clear();
        nodeSet.clear();
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
        {
            return -1;
        }
        Node node = it->second;
        nodeSet.erase(node);
        node.cnt += 1;
        node.time = ++time;
        nodeSet.insert(node);
        it->second = node;
        return node.value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it == cache.end())
        {
            if (cache.size() == cap)
            {
                cache.erase(nodeSet.begin()->key);
                nodeSet.erase(nodeSet.begin());
            }
            Node node = Node(1, ++time, key, value);
            cache.insert(make_pair(key, node));
            nodeSet.insert(node);
        }
        else
        {
            Node node = it->second;
            nodeSet.erase(node);
            node.cnt += 1;
            node.time = ++time;
            node.value = value;
            nodeSet.insert(node);
            it->second = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct Node1
{
    int  key, value, freq;
    Node1(int _key, int _value, int _freq) :key(_key), value(_value), freq(_freq) {}
};

class LFUCache {
private:
    int minFreq, cap;
    unordered_map<int, list<Node1>::iterator> key_iter;
    unordered_map<int, list<Node1>> freq_nodes;

public:
    LFUCache(int capacity) {
        minFreq = 0;
        cap = capacity;
        key_iter.clear();
        freq_nodes.clear();
    }

    int get(int key) {
        auto it = key_iter.find(key);
        if (it == key_iter.end())
        {
            return -1;
        }
        list<Node1>::iterator iter = it->second;
        int val = iter->value, freq = iter->freq;
        freq_nodes[freq].erase(iter);
        if (freq_nodes[freq].size() == 0)
        {
            freq_nodes.erase(freq);
            if (minFreq == freq)
            {
                minFreq += 1;
            }
        }
        freq_nodes[freq + 1].push_front(Node1(key, val, freq + 1));
        key_iter[key] = freq_nodes[freq + 1].begin();
        return val;
    }

    void put(int key, int value) {
        auto it = key_iter.find(key);
        if (it == key_iter.end())
        {
            if (key_iter.size() == cap)
            {
                auto it2 = freq_nodes[minFreq].back();
                key_iter.erase(it2.key);
                freq_nodes[minFreq].pop_back();
                if (freq_nodes[minFreq].size() == 0)
                {
                    freq_nodes.erase(minFreq);
                }
            }
            freq_nodes[1].push_front(Node1(key, value, 1));
            key_iter[key] = freq_nodes[1].begin();
            minFreq = 1;
        }
        else
        {
            list<Node1>::iterator iter = it->second;
            int freq = iter->freq;
            freq_nodes[freq].erase(iter);
            if (freq_nodes[freq].size() == 0)
            {
                freq_nodes.erase(freq);
                if (minFreq == freq)
                {
                    minFreq += 1;
                }
            }
            freq_nodes[freq + 1].push_front(Node1(key, value, freq + 1));
            key_iter[key] = freq_nodes[freq + 1].begin();
        }
    }
};