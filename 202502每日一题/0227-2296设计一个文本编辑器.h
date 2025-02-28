#pragma once
using namespace std;
#include <string>
#include <vector>

class TextEditor {
private:
    vector<char> left;
    vector<char> right;

public:
    TextEditor() {

    }

    void addText(string text) {
        for (char c : text) {
            left.push_back(c);
        }
    }

    int deleteText(int k) {
        int res = 0;
        for (; !left.empty() && k > 0; k--) {
            left.pop_back();
            res++;
        }
        return res;
    }

    string cursorLeft(int k) {
        while (!left.empty() && k-- > 0) {
            right.push_back(left.back());
            left.pop_back();
        }
        int n = left.size();
        return string(left.begin() + max(0, n - 10), left.end());
    }

    string cursorRight(int k) {
        while (!right.empty() && k-- > 0) {
            left.push_back(right.back());
            right.pop_back();
        }
        int n = left.size();
        return string(left.begin() + max(0, n - 10), left.end());
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */