#pragma once
using namespace std;
#include <queue>

class MyStack {
private:
    queue<int> queue1, queue2;
public:
    MyStack() {

    }

    void push(int x) {
        queue2.push(x);
        while (!queue1.empty())
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        swap(queue1, queue2);
    }

    int pop() {
        int x = queue1.front();
        queue1.pop();
        return x;
    }

    int top() {
        return queue1.front();
    }

    bool empty() {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {

    }

    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};