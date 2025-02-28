#pragma once
using namespace std;
#include <string>
#include <vector>

class BrowserHistory {
private:
    vector<string> urlVec;
    int curIdx;

public:
    BrowserHistory(string homepage) {
        urlVec.push_back(homepage);
        curIdx = 0;
    }

    void visit(string url) {
        while (curIdx < urlVec.size() - 1) {
            urlVec.pop_back();
        }
        urlVec.push_back(url);
        curIdx++;
    }

    string back(int steps) {
        curIdx = max(curIdx - steps, 0);
        return urlVec[curIdx];
    }

    string forward(int steps) {
        curIdx = min(curIdx + steps, (int)urlVec.size() - 1);
        return urlVec[curIdx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */