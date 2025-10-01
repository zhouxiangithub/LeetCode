#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    /*
         (passj+1)/(totalj+1)-passj/totalj > (passi+1)/(totali+1)-passi/totali
    <==> (totalj-passj)/[(totalj+1)*totalj] > (totali-passi)/[(totali+1)*totali]
    */
    struct Ratio
    {
        int pass, total;
        bool operator < (const Ratio& oth) const {
            return (long long)(oth.total - oth.pass) * (total + 1) * total > (long long)(total - pass) * (oth.total + 1) * oth.total;
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Ratio> q;
        for (auto& c : classes) {
            q.push({ c[0],c[1] });
        }

        for (int i = 0; i < extraStudents; i++) {
            auto [pass, total] = q.top();
            q.pop();
            q.push({ pass + 1,total + 1 });
        }

        double res = 0;
        for (int i = 0; i < classes.size(); i++) {
            auto [pass, total] = q.top();
            q.pop();
            res += 1.0 * pass / total;
        }
        return res / classes.size();
    }
};