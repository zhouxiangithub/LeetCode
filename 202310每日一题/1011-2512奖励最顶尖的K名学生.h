#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string, int> words;
        for (const auto& word : positive_feedback)
        {
            words[word] = 3;
        }
        for (const auto& word : negative_feedback)
        {
            words[word] = -1;
        }

        vector<vector<int>> score_sid;
        for (int i = 0; i < report.size(); i++)
        {
            stringstream ss;
            string str;
            int score = 0;
            ss << report[i];
            while (ss >> str)
            {
                if (words.count(str))
                {
                    score += words[str];
                }
            }
            score_sid.push_back({ -score,student_id[i] });
        }

        sort(score_sid.begin(), score_sid.end());

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(score_sid[i][1]);
        }
        return res;
    }
};