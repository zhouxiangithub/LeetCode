#pragma once
using namespace std;
#include <vector>
#include <map>

class Solution {
public:
    map<vector<int>, int> memo;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();

        vector<vector<int>> filterSpecial;
        for (auto& sp : special) {
            int totalCount = 0, totalPrice = 0;
            for (int i = 0; i < n; i++) {
                totalCount += sp[i];
                totalPrice += sp[i] * price[i];
            }
            if (totalCount > 0 && sp[n] < totalPrice) { // ֵ�ù�������,�ȵ������
                filterSpecial.emplace_back(sp);
            }
        }

        return dfs(price, special, needs, filterSpecial, n);
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> curNeeds, vector<vector<int>>& filterSpecial, int n) {
        if (!memo.count(curNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; i++) {
                minPrice += curNeeds[i] * price[i]; // ԭ�۹���
            }
            for (auto& curSpecial : filterSpecial) {
                vector<int> nxtNeeds;
                for (int i = 0; i < n; i++) {
                    if (curSpecial[i] > curNeeds[i]) { // ���ܹ��򳬳������嵥ָ����������Ʒ
                        break;
                    }
                    nxtNeeds.emplace_back(curNeeds[i] - curSpecial[i]);
                }
                if (nxtNeeds.size() == n) {
                    minPrice = min(minPrice, dfs(price, special, nxtNeeds, filterSpecial, n) + curSpecial[n]);
                }
            }
            memo[curNeeds] = minPrice;
        }
        return memo[curNeeds];
    }
};