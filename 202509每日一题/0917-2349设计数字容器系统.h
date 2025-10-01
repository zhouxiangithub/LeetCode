#pragma once
using namespace std;
#include <unordered_map>
#include <queue>

class NumberContainers {
private:
    unordered_map<int, int> nums;
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> heaps;

public:
    NumberContainers() {

    }

    void change(int index, int number) {
        nums[index] = number;
        heaps[number].push(index);
    }

    int find(int number) {
        while (!heaps[number].empty() && nums[heaps[number].top()] != number) {
            heaps[number].pop();
        }
        if (heaps[number].empty()) {
            return -1;
        }
        return heaps[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */