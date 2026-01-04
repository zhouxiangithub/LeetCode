#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    bool checkCodeAndActive(string code, bool isActive) {
        for (char ch : code) {
            if (!(isActive && (ch == '_' || isalnum(ch)))) {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> res;
        vector<string> groups[4];
        for (int i = 0; i < code.size(); i++) {
            if (code[i].size() && checkCodeAndActive(code[i], isActive[i])) {
                if (businessLine[i] == "electronics") {
                    groups[0].push_back(code[i]);
                }
                else if (businessLine[i] == "grocery") {
                    groups[1].push_back(code[i]);
                }
                else if (businessLine[i] == "pharmacy") {
                    groups[2].push_back(code[i]);
                }
                else if (businessLine[i] == "restaurant") {
                    groups[3].push_back(code[i]);
                }
            }
        }
        for (auto& group : groups) {
            sort(group.begin(), group.end());
            res.insert(res.end(), group.begin(), group.end());
        }
        return res;
    }
};