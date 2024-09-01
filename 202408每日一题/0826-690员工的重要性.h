#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

/*
// Definition for Employee.
*/
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    unordered_map<int, Employee*> mp;

    int dfs(int id) {
        Employee* employee = mp[id];
        int totalImp = employee->importance;
        for (int subId : employee->subordinates) {
            totalImp += dfs(subId);
        }
        return totalImp;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for (auto& employee : employees) {
            mp[employee->id] = employee;
        }
        return dfs(id);
    }
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto& employee : employees) {
            mp[employee->id] = employee;
        }

        int totalImp = 0;
        queue<int> que;
        que.push(id);
        while (!que.empty()) {
            int curId = que.front();
            que.pop();
            Employee* employee = mp[curId];
            totalImp += employee->importance;
            for (int subId : employee->subordinates) {
                que.push(subId);
            }
        }
        return totalImp;
    }
};