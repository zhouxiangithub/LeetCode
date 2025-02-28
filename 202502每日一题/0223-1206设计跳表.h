#pragma once
using namespace std;
#include <vector>
#include <random>

constexpr int MAX_LEVEL = 32;
constexpr double P_FACTOR = 0.25;

struct SkiplistNode {
    int val;
    vector<SkiplistNode*> forward;
    SkiplistNode(int _val, int _maxLevel = MAX_LEVEL) :val(_val), forward(_maxLevel, nullptr) {}
};

class Skiplist {
private:
    SkiplistNode* head;
    int level;
    mt19937 gen{ random_device{}() };
    uniform_real_distribution<double> dis;

public:
    Skiplist() :head(new SkiplistNode(-1)), level(0), dis(0, 1) {

    }

    bool search(int target) {
        SkiplistNode* curr = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < target) {
                curr = curr->forward[i];
            }
        }
        curr = curr->forward[0];
        if (curr && curr->val == target) {
            return true;
        }
        return false;
    }

    void add(int num) {
        vector<SkiplistNode*> update(MAX_LEVEL, head);
        SkiplistNode* curr = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        int lv = randomLevel();
        level = max(level, lv);
        SkiplistNode* newNode = new SkiplistNode(num, lv);
        for (int i = 0; i < lv; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    bool erase(int num) {
        vector<SkiplistNode*> update(MAX_LEVEL, nullptr);
        SkiplistNode* curr = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        curr = curr->forward[0];
        if (!curr || curr->val != num) {
            return false;
        }
        for (int i = 0; i < level; i++) {
            if (update[i]->forward[i] != curr) {
                break;
            }
            update[i]->forward[i] = curr->forward[i];
        }
        delete curr;
        while (level > 1 && head->forward[level - 1] == nullptr) {
            level--;
        }
        return true;
    }

    int randomLevel() {
        int lv = 1;
        while (dis(gen) < P_FACTOR && lv < MAX_LEVEL) {
            lv++;
        }
        return lv;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */