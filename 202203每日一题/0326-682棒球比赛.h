#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        vector<int> vec;
        for (auto& op : ops)
        {
            int n = vec.size();
            switch (op[0])
            {
            case '+':
                sum += vec[n - 1] + vec[n - 2];
                vec.push_back(vec[n - 1] + vec[n - 2]);
                break;
            case 'D':
                sum += 2 * vec[n - 1];
                vec.push_back(2 * vec[n - 1]);
                break;
            case 'C':
                sum -= vec[n - 1];
                vec.pop_back();
                break;
            default:
                sum += stoi(op);
                vec.push_back(stoi(op));
                break;
            }
        }
        return sum;
    }
};