#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        int total = accumulate(count.begin(), count.end(), 0);
        int minimum = 256;
        int maximum = 0;
        double mean = 0.0;
        double median = 0.0;
        int mode = 0;
        
        int left = (total + 1) / 2;
        int right = (total + 2) / 2;
        int cnt = 0;
        int maxfreq = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (long long)count[i] * i;
            if (count[i] > maxfreq)
            {
                maxfreq = count[i];
                mode = i;
            }
            if (count[i] > 0)
            {
                if (minimum == 256)
                {
                    minimum = i;
                }
                maximum = i;
            }
            if (cnt < right && cnt + count[i] >= right)
            {
                median += i;
            }
            if (cnt < left && cnt + count[i] >= left)
            {
                median += i;
            }
            cnt += count[i];
        }
        mean = (double)sum / total;
        median = median / 2.0;
        return { (double)minimum,(double)maximum,mean,median,(double)mode };
    }
};