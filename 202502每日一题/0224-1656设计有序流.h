#pragma once
using namespace std;
#include <vector>
#include <string>

class OrderedStream {
private:
    int ptr;
    vector<string> stream;

public:
    OrderedStream(int n) {
        ptr = 1;
        stream.resize(n + 1);
    }

    vector<string> insert(int idKey, string value) {
        vector<string> res;
        stream[idKey] = value;
        while (ptr < stream.size() && !stream[ptr].empty()) {
            res.push_back(stream[ptr]);
            ptr++;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */